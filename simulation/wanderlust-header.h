/**
 * License: MIT
 * Copyright (c) 2013 Gerard Krol
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "ns3/header.h"
#include "packet.h"

namespace ns3 {

class WanderlustHeader: public Header {
public:
    WanderlustHeader() {
        memset(&contents, 0, sizeof(wanderlust_header_t));
    }
    virtual uint32_t GetSerializedSize(void) const {
        return sizeof(wanderlust_header_t);
    }
    virtual void Serialize(Buffer::Iterator start) const {
        start.Write((uint8_t*)&contents, sizeof(wanderlust_header_t));
    }
    virtual uint32_t Deserialize(Buffer::Iterator start) {
        start.Read((uint8_t*)&contents, sizeof(wanderlust_header_t));
        return sizeof(wanderlust_header_t);
    }
    virtual void Print(std::ostream &os) const {
        os << "Wanderlust packet " << contents.src_pubkey.getShortId() << " => " << contents.dst_pubkey.getShortId() << " type ";
        switch (contents.message_type) {
            case WANDERLUST_TYPE_DATA: os << "DATA"; break;
            case WANDERLUST_TYPE_SWAP_REQUEST: os << "SWAP REQUEST"; break;
            case WANDERLUST_TYPE_SWAP_RESPONSE: os << "SWAP RESPONSE"; break;
            case WANDERLUST_TYPE_SWAP_CONFIRMATION: os << "SWAP CONFIRMATION"; break;
            case WANDERLUST_TYPE_LOCATION_QUERY: os << "LOCATION QUERY"; break;
            case WANDERLUST_TYPE_LOCATION_ANSWER: os << "LOCATION ANSWER"; break;
            case WANDERLUST_TYPE_HELLO: os << "HELLO"; break;
            case WANDERLUST_TYPE_PING: os << "PING"; break;
            case WANDERLUST_TYPE_PONG: os << "PONG"; break;
            default: os << "UNKNOWN";
        }

    }
    virtual TypeId GetInstanceTypeId (void) const {
        return m_tid;
    }
    wanderlust_header_t contents;
private:
    TypeId m_tid;
};

}
