Menus
================================================================================

```
            ____________________
          O                      O
          O                      O
          O                      O
          O                      O
            ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾
```

Home
----

```
            ____________________
  (input) O hh:mm       ALARMS 0 O (cycle) (on/off)
  (input) O DD/MM    EDIT ALARMS O (menu)
  (input) O YYYY           --:-- O (input*) (quick-alarm)
  (cycle) O DAY             TEST O (trigger)
            ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾
```

EDIT ALARMS
-----------

```
            ____________________
   (menu) O <--            --:-- O (menu)
   (menu) O --:--          --:-- O (menu)
   (menu) O --:--          --:-- O (menu)
   (menu) O --:--          --:-- O (menu)
            ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾
```

Editing an alarm
----------------

```
            ____________________
   (menu) O <--         ACTIVE 0 O (cycle) (on/off)
 (input*) O --:--        PAUSE 0 O (input*) (count 0<=n<=9)
   (menu) O WEEKDAYS      TEMP 0 O (input*) (count 0<=n<=9)
          O                CLEAR O (trigger)
            ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾
```

WEEKDAYS
--------

```
            ____________________
   (menu) O <--            THU 0 O (cycle) (all on/off)
  (cycle) O 0 MON          FRI 0 O (cycle)
  (cycle) O 0 TUE          SAT 0 O (cycle)
  (cycle) O 0 WED          SUN 0 O (cycle)
            ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾
```



Other screens
================================================================================


Summary
-------

```
            ____________________
          O                  Q A O
          O      DAY 00 MON      O
          O     ___    --:--     O
          O     _ DAYS --:--     O
            ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾
```

* Row 1

  * Q - Shows when quick alarm is active.

  * A - Shows when ALARMS setting is active.

* Row 2

  Weekday, date and month.

* Row 3

  Next alarm, if any. Weekday and time.

* Row 4

  Time until next alarm. Days, hours and minutes.


Physical interface
================================================================================


Screen
------

**Location: front**

Used in settings mode.

Width: 20 characters.

Height: 4 rows.

--------------------------------------------------------------------------------


Clock / Scratchpad + Rotary encoder
-----------------------------------

**Location: front**

4 digits (7-segment).


### In normal mode: *clock*

Shows time when *snooze/show time button* is held, otherwise off.

Rotary encoder does nothing.


### In settings mode: *scratchpad*

Changed with rotary encoder. CW +, CCW -.

Press on encoder toggles between first (**XX**:00) and second (00:**XX**) group.
Long press on encoder clears value (sets 0000).

--------------------------------------------------------------------------------


OSB
---

**Location: front**

"On screen buttons". 4 on each side of the display matching the display's
character rows.


### Interactions

* Press

  Pressed and released quickly.

* Short hold

  Held for more than 1 sec but less than 2 sec.

* Long hold

  Held for more than 2 sec.

Different osb modes can treat press and hold in different ways.


### Modes (as seen in Menus)

* (input)

  When pressed, copies value from *scratchpad* to input field.
  Resets *scratchpad*.

  Short hold copies value to *scratchpad*.

  * (input*)

    Long hold resets field to default value or null (empty).

  If the field is validated or in some way more limited than the *scratchpad*,
  any attempt to input an invalid value is ignored. Any prior value in the field
  is kept intact.

* (menu)

  When pressed, switches to another menu.

* (cycle)

  When pressed, cycles through possible values.

* (trigger)

  When pressed (or held), activates a function.
  Press, short hold and long hold can be used for different functions.


--------------------------------------------------------------------------------


Snooze/show time button
-----------------------

**Location: top**

When pressed, snoozes alarm if active.

When held, shows time on *clock/scratchpad*.

When held for more than 2 seconds, shows *Summary* on screen.

--------------------------------------------------------------------------------


Cancel alarm button
-----------------

**Location: right side**

When pressed, cancels alarm if active.

--------------------------------------------------------------------------------


Settings mode switch
--------------------

**Location: front**

Type: 2-position toggle switch.

When on, activates *settings mode*.

When off, deactivates *settings mode*.

When switching from off to on, current time is copied to *clock/scratchpad*.

--------------------------------------------------------------------------------


Alarm indicator
---------------

**Location: front**

Type: LED.

Lights up as long as *the* alarm is triggered. Serves as a reminder to cancel
the alarm if it is snoozed.


Functions
================================================================================


Checking alarms
---------------

If the ALARMS setting is on (1), all active alarms (ACTIVE=1) are checked at the
start of every minute. The quick-alarm (if active) is checked independently of the
ALARMS setting.

--------------------------------------------------------------------------------


Alarm states
------------

* Off (Default state)

  No alarm is currently triggered. This state is also reached when a triggered
  alarm is canceled.

* (Triggered) (category of states)

  Any active alarm (including quick-alarm) has triggered *the* alarm. *The*
  alarm will remain in the triggered state (any sub-state) until canceled.

  Other alarms will still be checked as normal.

  * Initial (default triggered state)

    *The* alarm is currently sounding [continuosly or in intervals]*. *The*
    alarm will continue to sound until snoozed, canceled or until {timeout}**.
    If another alarm is triggered, {timeout}** will be reset.

  * Repeat

    Same as *Initial*, except no timeout**.

  * Snoozed

    *The* alarm is currently snoozed. *The* alarm is paused for {snooze}.
    After {snooze}, the alarm will reset to *Repeat*.
    If another alarm is triggered, *the* alarm will reset to *Repeat*.

**In other words:** Valid global alarm states are: *Off*, *Initial*, *Repeat*
and *Snoozed*.

**To be decided*

***When an alarm is snoozed, the system can assume human presence and rely on
further intervention to eventually cancel the alarm. If not, it can not, and
must stop after {timeout} to avoid sounding indefinitely.


### Variables

* {snooze}: *To be decided*
* {timeout}: *To be decided*

--------------------------------------------------------------------------------


/Home/time and date fields
--------------------------

(hh:mm, DD/MM, YYYY, DAY)

As well as acting as input fields to set current time and date, the fields are
updated live at all times.

DD/MM will be validated and leap-year status of set current year will be taken
into account. YYYY will therefore need to be set *before* DD/MM to ensure
correct validation of 29/02 (29th of February).

DAY is not validated and does not affect nor is affected by other fields.

**Note:** Neither of the fields hh:mm, DD/MM, YYYY and DAY are nullable and
will, at initial startup, be initialized from the RTC module (Real Time Clock).

--------------------------------------------------------------------------------


/Home/ALARMS
--------------------------

Master switch for alarms on/off. Does not impact individual alarms'
ACTIVE-status. If off, no alarms will be checked or triggered.

**Exception:** The quick-alarm (if active) is not affected and will still be
checked.

--------------------------------------------------------------------------------


/Home/quick-alarm
-----------------

If quick-alarm time is set (from *scratchpad*), the alarm will trigger like any
normal alarm on the next occurrence of the set time. When triggered, the time
will be cleared and the alarm will be disabled.

Empty field (--:--) means no quick-alarm currently active.

--------------------------------------------------------------------------------


/Home/test
----------

Triggers the alarm function like any normal scheduled alarm.

--------------------------------------------------------------------------------


/Editing an alarm/PAUSE and TEMP
--------------------------------

PAUSE and TEMP serve to temporarily override any scheduling set in the alarm's
WEEKDAYS menu. **Neither will override the alarm's ACTIVE status in any way**.

Both PAUSE and TEMP are cleared (set to 0) if the alarm is disabled (ACTIVE=0).
Any attempt to modify the value of PAUSE or TEMP when the alarm is disabled
(ACTIVE=0) is ignored. If any of the fields is changed to a value other than 0,
the other will be cleared (set to 0).

**In other words:** Only one of PAUSE or TEMP can be active (greater than 0) at
once. Neither PAUSE nor TEMP can be active (greater than 0) if the alarm is
disabled (ACTIVE=0).


### PAUSE

If PAUSE is greater than 0, whether or not the alarm is scheduled on that day,
the alarm is silenced and PAUSE is decreased by 1.


### TEMP

If TEMP is greater than 0, whether or not the alarm is scheduled on that day,
the alarm is triggered and TEMP is decreased by 1.
