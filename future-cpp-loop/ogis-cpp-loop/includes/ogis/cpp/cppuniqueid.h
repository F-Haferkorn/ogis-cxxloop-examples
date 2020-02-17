#pragma once

#define CPPMACRO_UNIQUE_ID(ID_TAG) \
    UNIQUE_##ID_TAG##_##LINE##_##__LINE__##_##__COUNTER__
