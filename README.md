# Souffle with Lattices

Project by Mitchel Myers and Ryan Pasculano

## Steps to Build

*These steps are the same as standard souffle. The same prerequisites are expected as listed on the [build page](https://souffle-lang.github.io/build). We present the Ubuntu/Debian build steps, refer to the build page for other options.*

In a terminal, open in the root directory of this project run the following commands

```
 sh ./bootstrap
./configure
make
```

This may take a while, especially `make`.

## Running tests

To run tests, first switch to the `project-tests` directory

```
cd project-tests
```

### Compiled

From here, you can run compile and run programs using the following command.

```
make run-compiled PROG=<prog> TESTCASE=<testcase> THREADS=<nthreads>
```

`<prog>` can be replaced by either `const_prop` or `sign` depending on the analysis you want to do.

`<testcase>` can be replaced by the name of one of the fact file directories in `project-tests/facts`. For example, to run the `prog-50L-3000` test, use `TESTCASE=prog-50L-3000`

`<nthreads>` is the number of threads to use. Defaults to 1 if omitted.

Here's an concrete example (run from `project-tests`):

```
make run-compiled PROG=const_prop TESTCASE=prog-200L-5000 THREADS=2
```

This creates an output directory at `project-tests/<prog>/out/<testcase>/compiled-<nthreads>`

### Interpreted

For comparison, you can also use

```
make run-interpreted PROG=<prog> TESTCASE=<testcase>
```

The arguments are the same, except threads is ignored, because the interpreted does not appear to be parallelized (Note, a future version of Souffle parallelized the interpreter).

Example (run from `project-tests`):

```
make run-interpreted PROG=const_prop TESTCASE=prog-200L-5000
```

This creates an output directory at `project-tests/<prog>/out/<testcase>/interpreted`
