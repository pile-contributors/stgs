if (NOT STGS_BUILD_MODE)
    set (STGS_BUILD_MODE STATIC)
endif ()

include(pile_support)
pileInclude (Stgs)
stgsInit(${STGS_BUILD_MODE})
