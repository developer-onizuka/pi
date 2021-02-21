#!/usr/bin/env python

from mpi4py import MPI
import numpy
import sys
import time

mpi_info=MPI.Info.Create()
mpi_info.Set("add-hostfile","/home/pi/machines_openmpi.txt")

#N = 1000000
N = 100000000

print "--------------- PI ---------------"
print "N: %d" % N

comm = MPI.COMM_SELF.Spawn(sys.executable,
                           args=['cluster-pi.py'],
                           maxprocs=20,
                           info=mpi_info)
# Broadcast a message from one process to all other processes in a group
comm.bcast(N, root=MPI.ROOT)

PI = 0.0
# Reduce
start = time.time()
PI = comm.reduce(None, PI, op=None, root=MPI.ROOT)
elasped_time = time.time() - start

print "PI =", PI
print 'elasped time = ',elasped_time

comm.Disconnect()

print "----------------------------------"
