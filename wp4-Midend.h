/*
Copyright 2020 Paul Zanna.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#ifndef _BACKENDS_WP4_MIDEND_H_
#define _BACKENDS_WP4_MIDEND_H_

#include "ir/ir.h"
#include "wp4-Options.h"
#include "frontends/common/resolveReferences/referenceMap.h"
#include "frontends/p4/typeMap.h"

namespace WP4 {

class MidEnd {
    std::vector<DebugHook> hooks;
 public:
    P4::ReferenceMap       refMap;
    P4::TypeMap            typeMap;

    void addDebugHook(DebugHook hook) { hooks.push_back(hook); }
    const IR::ToplevelBlock* run(WP4Options& options, const IR::P4Program* program, std::ostream* outStream = nullptr);
};

}  // namespace WP4

#endif /* _BACKENDS_WP4_MIDEND_H_ */
