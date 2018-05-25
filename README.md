# Data Grid

A simple GUI component for displaying tables using the Qt framework.
Examples include a program to display files of [TSV](https://en.wikipedia.org/wiki/Tab-separated_values) data.

## Current functionality

* Provides model and view classes
* Displays a grid
* Displays scroll bars
* Displays model content
* Repaints
* Select a cell with mouse pointer
* Move selected cell using arrow keys

## On cygwin

To build:

```
$ cd src
$ make clean all
```

To start the x-server:
```
$ xinit &
```

To run the demo:

```
$ export DISPLAY=:0
$ ./bin/multiplicationgrid
```

To display a file of [TSV](https://en.wikipedia.org/wiki/Tab-separated_values) data:

```
$ export DISPLAY=:0
$ cat ../bin/test.tsv | ../bin/tsvgrid 
```


