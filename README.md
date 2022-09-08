Producer/Consumer Problem1 General Information:

We can state the work as follows: two processes share the same memory area (in our case they share the same file).   
One process will write to the end of the file a random value ∈[0,99].This process is called producer.  
The other process, the consumer, will remove these values from the beginning of the file (printing it to the screen).   
The producer will insert a value into the file and will wait "s" seconds, where "s" is a random integer ∈[1,3].  
The consumer will also use the same waiting logic to remove elements from the file.  
The file name will be buffer.txt and will be initialized with 10 integers (one integer per line).  
To avoid concurrency problems when accessing the filebuffer.txt, 
before writing or reading the filebuffer.txt the processes must create a filebuffer.txt.lock that indicates that the buffer.txt is being used.   
When finished writing or reading the buffer.txt.lock must be deleted.  
So before you write or read a file you should check if the filebuffer.txt.lock exists.  
If that file exists then the process should wait until it is available to read or write to buffer.txt.  
The job should be done using the fork call.  

Example of execution:
$ ./producer-consumer
[Consumer] 91
[Consumer] 10
[Producer] 62
[Consumer] 33
[Consumer] 79
[Producer] 9
[Producer] 52
[Producer] 34
