//
//  DyldSimulator.hpp
//  iblessing
//
//  Created by soulghost on 2020/4/27.
//  Copyright © 2020 soulghost. All rights reserved.
//

#ifndef DyldSimulator_hpp
#define DyldSimulator_hpp

#include "Object.hpp"
#include <vector>
#include <mach-o/loader.h>

typedef std::function<void (uint64_t addr, uint8_t type, const char *symbolName, uint8_t symbolFlags, uint64_t addend, uint64_t libraryOrdinal, const char *msg)> DyldBindHandler;

NS_IB_BEGIN

class DyldSimulator {
public:
    static bool eachBind(uint8_t *mappedData, std::vector<struct segment_command_64 *> segmentHeaders, dyld_info_command *dyldinfo, DyldBindHandler handler);
};

NS_IB_END

#endif /* DyldSimulator_hpp */
