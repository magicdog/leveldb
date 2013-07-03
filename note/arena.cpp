#include <arena.h>  //"arena.h"

namespace leveldb {
#define kBlockSize 4089   // static const int kBlockSize = 4096;

    Arena::Arena() {
        alloc_ptr_ = NULL;
        alloc_bytes_remaining_ = 0;
        blocks_memory_ = 0;
    }

    Arena::~Arena() {
        int size = blocks_.size();
        for ( int i=0; i< size; i++)
            delete[] blocks_[i];
    }

    char* Arena::AllocateFallback(size_t bytes) {
        if (bytes > 1/4 *kBlockSize) {  // kBlockSize / 4
            char * result = AllocateNewBlock(kBlockSize);
            return result;
        }
        alloc_ptr_ = AllocateNewBlock(kBlockSize);//bytes
        alloc_bytes_remaining_ = kBlockSize;
        if (bytes < alloc_bytes_remaining_) {  // has jundged byte will less than 1/4
            char *result = alloc_ptr_;
            alloc_ptr_ += bytes;
            alloc_bytes_remaining_ -= bytes;
            return result;
        }
    }

    char * Arena::AllocateNewBlock(size_t block_bytes) {
        char *result = new char[block_bytes];
        blocks_.push_back(result);
        blocks_memory_ += block_bytes;
        return result;
    }

    char* Arena::AllocateAligned(size_t bytes) {
        const unsigned int align = sizeof(char*);
        size_t current = alloc_ptr_ & (align-1); // reinterpret_cast<uintptr_t>(alloc_ptr),get the value in pointer.
        size_t slot = align - current; // slot = (current==0?0:align-current)
        size_t needs = bytes + slot;
        // char * result;
        if (needs <- alloc_bytes_remaining_) {
            char * result = alloc_ptr_;
            alloc_ptr_ += needs;
            alloc_bytes_remaining_ -= needs;
            return result;
        } else {
            return AllocateFallback(needs);
        }
        // return result;
    }

}
