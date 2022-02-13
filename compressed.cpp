#include <iostream>
#include <sstream>
#include <boost>
#include <boost/iostreams/filtering_streambuf.hpp>
#include <boost/iostreams/copy.hpp>
#include <boost/iostreams/filter/zlib.hpp>
#include <cpp-base64/base64.h>

std::string string_compress_encode(const std::string &data)
{
    std::stringstream compressed;
    std::stringstream original;
    original << data;
    boost::iostreams::filtering_streambuf<boost::iostreams::input> out;
    out.push(boost::iostreams::zlib_compressor());
    out.push(original);
    boost::iostreams::copy(out, compressed);

    /**need to encode here **/
    std::string compressed_encoded = base64_encode(reinterpret_cast<const unsigned char*>(compressed.c_str()), compressed.length());

    return compressed_encoded;
}

std::string string_decompress_decode(const std::string &data)
{
    std::stringstream compressed_encoded;
    std::stringstream decompressed;
    compressed_encoded << data;

    /** first decode  then decompress **/
    std::string compressed = base64_decode(compressed_encoded);

    boost::iostreams::filtering_streambuf<boost::iostreams::input> in;
    in.push(boost::iostreams::zlib_decompressor());
    in.push(compressed);
    boost::iostreams::copy(in, decompressed);
    return decompressed.str();
}

int main(void){
    std::string a = "785ecb4c2e49abaeca314c8a372c8e4f3630c8892f324ccf28b1af050079eb092d";
    std::string decompressed = string_decompress_decode(a);
    std::cout << decompressed << "\n";
    return 0;
}