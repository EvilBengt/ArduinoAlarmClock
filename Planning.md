Menus
=====

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
  (input) O --:--       ALARMS 0 O (toggle)
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
   (menu) O <--         ACTIVE 0 O (toggle) (on/off)
  (input) O --:--        PAUSE 0 O (input*) (count)
   (menu) O WEEKDAYS      TEMP 0 O (input*) (count)
          O                CLEAR O (trigger)
            ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾
```

WEEKDAYS
--------

```
            ____________________
   (menu) O <--            THU 0 O (toggle) (all toggles on/off)
 (toggle) O 0 MON          FRI 0 O (toggle)
 (toggle) O 0 TUE          SAT 0 O (toggle)
 (toggle) O 0 WED          SUN 0 O (toggle)
            ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾
```



Physical interface
==================


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

Shows time when *snooze/show time button* is held.


#### In settings mode:

Changed with rotary encoder. CW +, CCW -.

Press on encoder toggles between first (**XX**:00) and second (00:**XX**) group.
Long press on encoder clears value (sets 0000).

--------------------------------------------------------------------------------


OSB
---

**Location: front**

"On screen buttons". 4 on each side of the display.


#### Modes

* (input)

  When pressed, copies set value from *scratchpad* to input field.
  Resets *scratchpad*.

  Short hold copies value to *scratchpad*.

  * (input*)

    Long hold clears field.

  If the field is validated or in some way more limited than the *scratchpad*,
  any attempt to input an invalid value is ignored. Any prior value in the field
  is kept intact.

* (menu)

  When pressed, switches to another menu.

* (toggle)

  When pressed, toggles field/value on/off.

* (cycle)

  When pressed, cycles through possible values.

* (trigger)

  When pressed, activates a function.

--------------------------------------------------------------------------------


Snooze/show time button
-----------------------

**Location: top**

When pressed, snoozes alarm if active.

When held, shows time on *clock/scratchpad*.

--------------------------------------------------------------------------------


Cancel alarm button
-----------------

**Location: back**

When pressed, cancels alarm if active.

--------------------------------------------------------------------------------


Settings mode switch
--------------------

**Location: front**

Type: 2-position toggle switch.

When on, activates *settings mode*.

When off, deactivates *settings mode*.

When switching from off to on, current time is copied to *clock/scratchpad*.



Function
========


Checking alarms
---------------

If the ALARMS setting is on (1), all active alarms are checked at the start of
every minute. Any set quick-alarm is checked independently of the ALARMS
setting.

An alarm is considered active if any of the following is true:

* Its ACTIVE setting is on (1) *AND* PAUSE is 0.
* Its TEMP setting is greater than 0.

--------------------------------------------------------------------------------


Snoozing alarms
---------------

If a sounding alarm is snoozed (with *Snooze/show time button*), the alarm
pauses for {snooze}. The alarm also goes from mode A to mode B.


* Mode A

  Alarm sounds [continuosly or in intervals]* until canceled or {timeout}.


* Mode B

  Alarm sounds [continuosly or in intervals]* indefinitely, until canceled.


**To be decided*


#### Variables

* {snooze}: *To be decided*
* {timeout}: *To be decided*

--------------------------------------------------------------------------------


/Home/time and date fields
--------------------------

(--:--, DD/MM, YYYY, DAY)

As well as acting as input fields to set current time and date, the fields are
updated live at all times.

DD/MM will be validated and leap-year status of set current year will be taken
into account. YYYY will therefore need to be set *before* DD/MM to ensure
correct validation of 29/02 (29th of February).

DAY is not validated and does not affect nor is affected by other fields.

--------------------------------------------------------------------------------


/Home/ALARMS
--------------------------

Master switch for alarms on/off. Does not impact individual alarms' set
ACTIVE-status. If off, no alarms will be checked or triggered.

**Exception:** Any active quick-alarm is not affected and will still be checked.

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

#### PAUSE

Number of times to silence the alarm. When the alarm triggers and PAUS is
greater than 0, the alarm is immediately canceled and PAUS is decreased by 1.

#### TEMP

Number of times to force the alarm to trigger. If the alarm is disabled and
TEMP is greater than 0, the alarm will behave as if it's enabled. When the alarm
is triggered, TEMP is decreased by 1.

#### Both

Both PAUSE and TEMP are cleared (set to 0) if the alarm's ACTIVE status is
changed.
