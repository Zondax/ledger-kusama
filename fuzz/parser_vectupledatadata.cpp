#include <cassert>
#include <cstdint>
#include <cstdio>
#include "substrate_types.h"
#include "substrate_functions.h"

#ifdef NDEBUG
#error "This fuzz target won't work correctly with NDEBUG defined, which will cause asserts to be eliminated"
#endif


using std::size_t;

static char PARSER_KEY[16384];
static char PARSER_VALUE[16384];

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
    pd_VecTupleDataData_t obj;
    parser_context_t ctx;
    parser_error_t rc;

    ctx.buffer = data;
    ctx.bufferLen = size;
    ctx.offset = 0;

    rc = _readVecTupleDataData(&ctx, &obj);
    if (rc != parser_ok) {
        return 0;
    }

    uint8_t page_idx = 0;
    uint8_t page_count = 1;
    while (page_idx < page_count) {
        rc = _toStringVecTupleDataData(&obj,
                                       PARSER_VALUE, sizeof(PARSER_VALUE),
                                       page_idx, &page_count);
        if (rc != parser_ok) {
            return 0;
        }

        fprintf(stderr, "value %d / %d = %s\n", page_idx, page_count, PARSER_VALUE);
        page_idx += 1;
    }

    return 0;
}
