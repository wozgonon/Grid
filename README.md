# Data Grid

A simple GUI component for displaying tables using the Qt framework.

Currently:
* Provides model and view classes
* Displays a grid
* Displays scroll bars
* Displays model content
* Repaints
* Select a cell with mouse pointer

## On cygwin

To build:

```
$ make clean all
```

To start the x-server:
```
$ xinit &
```

To run the demo:

```
$ export DISPLAY=:0
$ ./grid
```


