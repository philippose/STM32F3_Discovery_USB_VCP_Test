target remote :3333

set remote hardware-breakpoint-limit 6
set remote hardware-watchpoint-limit 4

set mem inaccessible-by-default off
set print pretty

# Don't let GDB get confused while stepping
define hook-step
  mon cortex_m maskisr on
end
define hookpost-step
  mon cortex_m maskisr off
end

monitor reset halt
