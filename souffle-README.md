
# Soufflé

[![Build Status](https://travis-ci.org/souffle-lang/souffle.svg?branch=master)](https://travis-ci.org/souffle-lang/souffle)

Soufflé is a translator of Horn clauses into parallel C++. Soufflé language has similarities to Datalog, and is used as a domain-specific language for analysis problems. 

## Features of Soufflé

*   Efficient translation to parallel C++ of Datalog programs
*   Extended semantics of Pure Datalog, e.g., permitting unbounded recursions with numbers 
*   Simple component model for Datalog specifications 
*   Recursively defined record types (aka. constructors) for tuples 

### Added feature by Qing Gong

*   Conditional Operator (cond ? a : b)
*   Unary and Binary Case Function
*   Lattice Declaration
    *    Enum Type
    *    Lattice Association
    *    Lattice Relation
*   Modification in RAM
    *    LATCLEAN
    *    LATNORM
    
see paper ["From Datalog to FLIX: A Declarative Language for Fixed Points on Lattices"](https://plg.uwaterloo.ca/~olhotak/pubs/pldi16.pdf)

### To be added(Progress)

*   Ram Synthesiser for all features added (in progress)

## How to get Soufflé
 
Use git to obtain the source code of Soufflé. 

    $ git clone git@github.com:QXG2/souffle.git
    
Build instructions can be found [here](https://souffle-lang.github.io/build).     
basic: 
*   use "make -j8" for faster build. 
*   use "make doxygen-doc" to create the directory doc/html which will contain the file index.html to view the documentation.
*   In folder "souffle/dataflowTest", there are different sample programs involving lattice. Example: in foler "souffle/dataflowTest/Const_lattice/", try "make" to test the lattice feature.

# Original Soufflé

## [Home Page](https://souffle-lang.github.io/)

## [Documentation](https://souffle-lang.github.io/docs.html)

## [Github](https://github.com/souffle-lang/souffle)
