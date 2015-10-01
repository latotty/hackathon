## INFO ##
## INFO ##

from itertools import count
from kb.rpi2   import Context, Event

context = Context()
event   = Event(context)
counter = count()

@context
def on_start(*args, **kwargs):
    print('Inside: on_start')

@context
def on_cycle_begin(*args, **kwargs):
    print('Inside: on_cycle_begin')
    if next(counter) > 2:
        context.stop()

@context
def on_cycle_end(*args, **kwargs):
    print('Inside: on_cycle_end')

@context
def on_stop(*args, **kwargs):
    print('Inside: on_stop')

event.activate()
context.start()