/* INFO **
** INFO */

/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/* Include standard headers */
#include <stddef.h>
/*  type  : size_t */

/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/* Include kibu headers */
#include <kb/errors.h>
/*  type  : kb_Error */


/*----------------------------------------------------------------------------*/
static const char *const UNKNOWN  = "(Unknown Error)";
static const char *const ERRORS[] =
{
    [kb_OKAY]                       = "kb_OKAY",
    [kb_FAIL]                       = "kb_FAIL",
    [kb_SELF_IS_NULL]               = "kb_SELF_IS_NULL",
    [kb_ARG1_IS_NULL]               = "kb_ARG1_IS_NULL",
    [kb_ARG2_IS_NULL]               = "kb_ARG2_IS_NULL",
    [kb_ARG3_IS_NULL]               = "kb_ARG3_IS_NULL",
    [kb_ARG4_IS_NULL]               = "kb_ARG4_IS_NULL",
    [kb_ARG5_IS_NULL]               = "kb_ARG5_IS_NULL",
    [kb_ALLOC_FAIL]                 = "kb_ALLOC_FAIL",
    [kb_BCM2835_INIT_FAIL]          = "kb_BCM2835_INIT_FAIL",
    [kb_ITEM_NOT_IN_CONTAINER]      = "kb_ITEM_NOT_IN_CONTAINER",
    [kb_INVALID_PIN_ID]             = "kb_INVALID_PIN_ID",
    [kb_INVALID_PIN_STATE]          = "kb_INVALID_PIN_STATE",
    [kb_INVALID_PIN_ROLE]           = "kb_INVALID_PIN_ROLE",
    [kb_INVALID_PIN_PULL]           = "kb_INVALID_PIN_PULL",
    [kb_PIN_ALREADY_USED]           = "kb_PIN_ALREADY_USED",
    [kb_PIN_DOES_NOT_EXIST]         = "kb_PIN_DOES_NOT_EXIST",
    [kb_TOO_MANY_PINS_USED]         = "kb_TOO_MANY_PINS_USED",
    [kb_PIN_IS_GROUND]              = "kb_PIN_IS_GROUND",
    [kb_PIN_IS_POWER_V3_3]          = "kb_PIN_IS_POWER_V3_3",
    [kb_PIN_IS_POWER_V5]            = "kb_PIN_IS_POWER_V5",
    [kb_PIN_IS_RESERVED]            = "kb_PIN_IS_RESERVED",
    [kb_PIN_INDEX_IS_OUT_OF_RANGE]  = "kb_PIN_INDEX_IS_OUT_OF_RANGE",
    [kb_SENSOR_IS_NOT_IN_EVENT]     = "kb_SENSOR_IS_NOT_IN_EVENT",
    [kb_NO_EVENT_ACTIVATED]         = "kb_NO_EVENT_ACTIVATED",
    [kb_EVENT_NOT_BOUND_TO_CONTEXT] = "kb_EVENT_NOT_BOUND_TO_CONTEXT",
    [kb_EVENT_LOOP_ALREADY_RUNNING] = "kb_EVENT_LOOP_ALREADY_RUNNING",
};


/*----------------------------------------------------------------------------*/
const char *
kb_Error_str(kb_Error error)
{
    switch (error)
    {
        case kb_OKAY:
            return ERRORS[kb_OKAY];
        case kb_FAIL:
            return ERRORS[kb_FAIL];
        case kb_SELF_IS_NULL:
            return ERRORS[kb_SELF_IS_NULL];
        case kb_ARG1_IS_NULL:
            return ERRORS[kb_ARG1_IS_NULL];
        case kb_ARG2_IS_NULL:
            return ERRORS[kb_ARG2_IS_NULL];
        case kb_ARG3_IS_NULL:
            return ERRORS[kb_ARG3_IS_NULL];
        case kb_ARG4_IS_NULL:
            return ERRORS[kb_ARG4_IS_NULL];
        case kb_ARG5_IS_NULL:
            return ERRORS[kb_ARG5_IS_NULL];
        case kb_ALLOC_FAIL:
            return ERRORS[kb_ALLOC_FAIL];
        case kb_BCM2835_INIT_FAIL:
            return ERRORS[kb_BCM2835_INIT_FAIL];
        case kb_ITEM_NOT_IN_CONTAINER:
            return ERRORS[kb_ITEM_NOT_IN_CONTAINER];
        case kb_INVALID_PIN_ID:
            return ERRORS[kb_INVALID_PIN_ID];
        case kb_INVALID_PIN_STATE:
            return ERRORS[kb_INVALID_PIN_STATE];
        case kb_INVALID_PIN_ROLE:
            return ERRORS[kb_INVALID_PIN_ROLE];
        case kb_INVALID_PIN_PULL:
            return ERRORS[kb_INVALID_PIN_PULL];
        case kb_PIN_ALREADY_USED:
            return ERRORS[kb_PIN_ALREADY_USED];
        case kb_PIN_DOES_NOT_EXIST:
            return ERRORS[kb_PIN_DOES_NOT_EXIST];
        case kb_TOO_MANY_PINS_USED:
            return ERRORS[kb_TOO_MANY_PINS_USED];
        case kb_PIN_IS_GROUND:
            return ERRORS[kb_PIN_IS_GROUND];
        case kb_PIN_IS_POWER_V3_3:
            return ERRORS[kb_PIN_IS_POWER_V3_3];
        case kb_PIN_IS_POWER_V5:
            return ERRORS[kb_PIN_IS_POWER_V5];
        case kb_PIN_IS_RESERVED:
            return ERRORS[kb_PIN_IS_RESERVED];
        case kb_PIN_INDEX_IS_OUT_OF_RANGE:
            return ERRORS[kb_PIN_INDEX_IS_OUT_OF_RANGE];
        case kb_SENSOR_IS_NOT_IN_EVENT:
            return ERRORS[kb_SENSOR_IS_NOT_IN_EVENT];
        case kb_NO_EVENT_ACTIVATED:
            return ERRORS[kb_NO_EVENT_ACTIVATED];
        case kb_EVENT_NOT_BOUND_TO_CONTEXT:
            return ERRORS[kb_EVENT_NOT_BOUND_TO_CONTEXT];
        case kb_EVENT_LOOP_ALREADY_RUNNING:
            return ERRORS[kb_EVENT_LOOP_ALREADY_RUNNING];
        default:
            return UNKNOWN;
    }
}
