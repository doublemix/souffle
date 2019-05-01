
# [Soufflé](https://souffle-lang.github.io)

[![Build Status](https://travis-ci.org/souffle-lang/souffle.svg?branch=master)](https://travis-ci.org/souffle-lang/souffle)

Soufflé is a translator of Horn clauses into parallel C++. Soufflé language has similarities to Datalog, and is used as a domain-specific language for analysis problems. 

## Features of Soufflé

*   Efficient translation to parallel C++ of Datalog programs
*   Extended semantics of Pure Datalog, e.g., permitting unbounded recursions with numbers 
*   Simple component model for Datalog specifications 
*   Recursively defined record types (aka. constructors) for tuples 

### To be added

*   Lattice definition
*   Monotone Filter Functions
*   Monotone Functions  

### Progress

*   ParseDriver, Ast Nodes (done)
*   Ast to Ram translation (almost done, except lattice association)
*   Ram Interpreter and/or Synthesiser (in progress)

see paper ["From Datalog to FLIX: A Declarative Language for Fixed Points on Lattices"](https://plg.uwaterloo.ca/~olhotak/pubs/pldi16.pdf)

## How to get Soufflé
 
Use git to obtain the source code of Soufflé. 

    $ git clone git@github.com:QXG2/souffle.git
    
Build instructions can be found [here](http://souffle-lang.org/docs/build).     
basic: 
*   use "make -j8" for faster build. 
*   use "make doxygen-doc" to create the directory doc/html which will contain the file index.html to view the documentation.
*   In folder "souffle/src/dataflowTest/lattice", try "make" to test the lattice feature.

## [Home Page](http://souffle-lang.org)

## [Documentation](http://souffle-lang.org/docs/home)

## [Contributors](http://souffle-lang.org/docs/contributors/)

## [Issues](https://github.com/souffle-lang/souffle/issues)

## [License](https://github.com/souffle-lang/souffle/blob/master/licenses/SOUFFLE-UPL.txt)
