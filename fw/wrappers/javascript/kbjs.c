/* INFO **
** INFO */

/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/* Include standard headers */
#include <stdlib.h>
/*  const : EXIT_SUCCESS
            EXIT_FAILURE
    func  : exit */
#include <stdio.h>
/*  const : stderr
    func  : fputs */
#include <signal.h>
/*  const : SIGINT
    func  : signal
            raise
            SIG_DFL */

/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/* Include duktape headers */
#include <duktape.h>
/*  type  : duk_context
    func  : duk_create_heap_default
            duk_push_global_object
            duk_push_string
            duk_push_object
            duk_put_prop
            duk_pop
            duk_eval_file
            duk_destroy_heap */

/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/* Include kbjs headers */
#include "include/built_ins.h"
/*  func  : kbjs_register_built_ins */
#include "include/pin_ids.h"
/*  func  : kbjs_register_PinIds */
#include "include/contexts.h"
/*  func  : kbjs_register_Context */
#include "include/events.h"
/*  func  : kbjs_register_Event */
#include "include/sensors/leds.h"
/*  func  : kbjs_register_LED */
#include "include/sensors/four_keys.h"
/*  func  : kbjs_register_FourKeys */
#include "include/sensors/rgb_leds.h"
/*  func  : kbjs_register_RGBLED */
#include "include/sensors/step_motors.h"
/*  func  : kbjs_register_StepMotor */
#include "include/sensors/photo_resistors.h"
/*  func  : kbjs_register_PhotoResistor */
#include "include/sensors/rotary_encoders.h"
/*  func  : kbjs_register_RotaryEncoder */
#include "include/sensors/motion_sensors.h"
/*  func  : kbjs_register_MotionSensor */
#include "include/sensors/ultrasonic_sensors.h"
/*  func  : kbjs_register_UltrasonicSensor */
#include "include/sensors/hall_effects.h"
/*  func  : kbjs_register_HallEffect */


/*----------------------------------------------------------------------------*/
static duk_context *context = NULL;


/*----------------------------------------------------------------------------*/
static void
on_signal_interruption(int sig_num)
{
    /* If a duktape context was created destroy it */
    if (context)
        duk_destroy_heap(context);

    /* Report to the user */
    fputs("\nkbjs: Interrupted by user\n", stderr);

    /* Use the default handler and raise same signal */
    if (signal(sig_num, SIG_DFL))
    {
        fputs("kbjs: Cannot set signal handling\n", stderr);
        exit(EXIT_FAILURE);
    }

    raise(sig_num);
}


/*----------------------------------------------------------------------------*/
int
main(int argc,
     char const *argv[])
{
    /* Catch interruption signal */
    if (signal(SIGINT, on_signal_interruption))
    {
        fputs("kbjs: Cannot set signal handling\n", stderr);
        return EXIT_FAILURE;
    }

    /* If no file path passed */
    if (argc < 2)
    {
        fputs("kbjs: File path missing (first argument)\n", stderr);
        return EXIT_FAILURE;
    }

    /* Create duktape heap */
    if (!(context = duk_create_heap_default()))
    {
        fputs("kbjs: Internal allocation failed, during "
              "the creation of the duktape heap\n", stderr);
        return EXIT_FAILURE;
    }

    /* Create built-ins */
    kbjs_register_built_ins(context);

    /* Create modul objects */
    /* STACK: [global] */
    duk_push_global_object(context);
    /* STACK: [global, "kb"] */
    duk_push_string(context, "kb");
    /* STACK: [global, "kb", {}] */
    duk_push_object(context);
    /* STACK: [global, "kb", {}, "rpi2"] */
    duk_push_string(context, "rpi2");
    /* STACK: [global, "kb", {}, "rpi2", {}] */
    duk_push_object(context);
    /* STACK: [global, "kb", {}, "rpi2", {}, "sensors"] */
    duk_push_string(context, "sensors");
    /* STACK: [global, "kb", {}, "rpi2", {}, "sensors", {}] */
    duk_push_object(context);
    /* STACK: [global, "kb", {}, "rpi2", {sensors:{}}] */
    duk_put_prop(context, -3);
    /* STACK: [global, "kb", {rpi2:{sensors:{}}}] */
    duk_put_prop(context, -3);
    /* STACK: [global] */
    duk_put_prop(context, -3);
    /* STACK: [] */
    duk_pop(context);

    /* Load kbjs modules */
    kbjs_register_PinIds(context);
    kbjs_register_Context(context);
    kbjs_register_Event(context);
    kbjs_register_LED(context);
    kbjs_register_FourKeys(context);
    kbjs_register_RGBLED(context);
    kbjs_register_StepMotor(context);
    kbjs_register_PhotoResistor(context);
    kbjs_register_RotaryEncoder(context);
    kbjs_register_MotionSensor(context);
    kbjs_register_UltrasonicSensor(context);
    kbjs_register_HallEffect(context);

    /* Evaluate passed script */
    if (duk_peval_file(context, argv[1]))
    {
        fputs(duk_safe_to_string(context, -1), stderr);
        fputs("\n", stderr);
    }

    /* Clean up and terminate */
    duk_destroy_heap(context);
    return EXIT_SUCCESS;
}
