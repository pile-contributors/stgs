
# enable/disable cmake debug messages related to this pile
set (STGS_DEBUG_MSG OFF)

# make sure support code is present; no harm
# in including it twice; the user, however, should have used
# pileInclude() from pile_support.cmake module.
include(pile_support)

# initialize this module
macro    (stgsInit
          ref_cnt_use_mode)

    # default name
    if (NOT TEM_PILE_INIT_NAME)
        set(TEM_PILE_INIT_NAME "Stgs")
    endif ()

    # compose the list of headers and sources
    set(STGS_HEADERS
        "stgs.h")
    set(STGS_SOURCES
        "stgs.cc")

    pileSetSources(
        "${TEM_PILE_INIT_NAME}"
        "${STGS_HEADERS}"
        "${STGS_SOURCES}")

    pileSetCommon(
        "${TEM_PILE_INIT_NAME}"
        "0;0;1;d"
        "ON"
        "${ref_cnt_use_mode}"
        ""
        "category1"
        "tag1;tag2")

endmacro ()
