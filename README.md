# Simple Programming Exercises

## C++ Programs
Directory `cpp` has simple programming exercises written in c++.
The directory has a Makefile to build and test the programs.
To build the programs, go to `cpp` directory and run make:
```
$ cd cpp
$ make build
```

To build programs and run the unit tests:
```
$ cd cpp
$ make test
```

## Go programs
Directory `go` has programs written in the Go programming language.

### Fetch NAV
[MFAPI.in](https://mfapi.in) provides India's mutual fund api.
Program `mfnav.go` fetches the latest NAV for a Parag Parikh Long Term Equity Fund - Direct Growth.
The sample output of the program:
```
Fetch mutual fund's nav data
        Date |  Scheme Code |        NAV
  14-02-2025 |       122639 |   85.81100
```
