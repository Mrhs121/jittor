// ***************************************************************
// Copyright (c) 2020 Jittor. Authors: 
//     Guoye Yang <498731903@qq.com>
//     Dun Liang <randonlang@gmail.com>. 
// All Rights Reserved.
// This file is subject to the terms and conditions defined in
// file 'LICENSE.txt', which is part of this source code package.
// ***************************************************************
#include "curand_warper.h"
#include "init.h"

namespace jittor {

curandGenerator_t gen;

struct curand_initer {

inline curand_initer() {
    checkCudaErrors( curandCreateGenerator(&gen, CURAND_RNG_PSEUDO_DEFAULT) );
    add_set_seed_callback([](int seed) {
        checkCudaErrors( curandSetPseudoRandomGeneratorSeed(gen, seed) );
    });
    LOGv << "curandCreate finished";
}

inline ~curand_initer() {
    checkCudaErrors( curandDestroyGenerator(gen) );
    LOGv << "curandDestroy finished";
}

} init_;

} // jittor