#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

uint32_t A = 0x6a09e667;
uint32_t B = 0xbb67ae85;
uint32_t C = 0x3c6ef372;
uint32_t D = 0xa54ff53a;
uint32_t E = 0x510e527f;
uint32_t F = 0x9b05688c;
uint32_t G = 0x1f83d9ab;
uint32_t H = 0x5be0cd19;

const uint32_t k[64] = {
0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 
0x59f111f1, 0x923f82a4, 0xab1c5ed5, 0xd807aa98, 0x12835b01, 
0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7,
0xc19bf174, 0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 
0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da, 0x983e5152, 
0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 
0x06ca6351, 0x14292967, 0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 
0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85, 
0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 
0xd6990624, 0xf40e3585, 0x106aa070, 0x19a4c116, 0x1e376c08, 
0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 
0x682e6ff3, 0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 
0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2};


string message = "hello";

void padMessage(vector<uint32_t>& messageAsVector)
{
    uint64_t messageBitCount = message.size() * 8; //Each string char is 8 bits
    // cout << "Message len: " << messageBitCount << "\n";

    uint64_t amtToPad = (448 - (messageBitCount + 64) % 512) % 512;
    // cout << "Amount to pad: " << amtToPad << "\n";

    uint64_t afterPadding = messageBitCount + amtToPad + 64; 
    // cout << "Total bits after padding: " << afterPadding << "\n";

    messageAsVector.push_back(0x80000000);
    messageAsVector.resize(afterPadding/32);

    uint32_t sizeHigh = (uint32_t)(messageBitCount >> 32);
    // cout << "HIGH: " << sizeHigh <<"\n"; 
    uint32_t sizeLow = (uint32_t)messageBitCount;
    // cout << "LOW: " << sizeLow <<"\n";
    messageAsVector.push_back(sizeHigh);
    messageAsVector.push_back(sizeLow);

    // cout << "Final Message size in words: " << messageAsVector.size() << "\n";
    cout << "Final Message size in bits: " <<messageAsVector.size()*32 << "\n";
}

int main(int argc, char* argv[]){

    vector<uint32_t> messageAsVector;

    for(int i = 0 ; i < message.size(); i++){
        messageAsVector.push_back(static_cast<uint32_t>(message[i]));
    }

    cout << "Original messageAsVector: " << messageAsVector.size() << "\n";

    padMessage(messageAsVector);

    cout << "Padded messageAsVector: " << messageAsVector.size() << "\n";

}

