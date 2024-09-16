Character Device Driver is a Dynamic kernel Module, that is built separately from the kernel but runs as
part of the kernel. It provides an interface from the file-system to the hardware device. Implemented a
complete device driver from scratch that involved... registering driver with kernel device table, integrating
it into kernel code, Exporting dynamic kernel modules into the kernel and utilizing them from other
modules, Mapping of application layer system calls on to our custom made driver routines, like open, close,
write, read, trim etc. Managed concurrency issues using various synchronization techniques such as
semaphore, completion, spin-lock, blockind-IO, wait queues, seqlock. Implemented proc file-system for
device driver, timer, - Interrupt handling using task-lets.
