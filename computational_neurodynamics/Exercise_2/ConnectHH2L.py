"""
Computational Neurodynamics
Exercise 2

(C) Murray Shanahan et al, 2015
"""

from HHNetwork import HHNetwork
import numpy as np
import numpy.random as rn


def ConnectHH2L(N0, N1):
  """
  Constructs two layers of HH neurons and connects them together.
  Layers are arrays of N neurons. Parameters for regular spiking neurons
  extracted from:

  """

  F = 60/np.sqrt(N1)  # Scaling factor
  D = 5               # Conduction delay
  Dmax = 10           # Maximum conduction delay

  net = HHNetwork([N0, N1], Dmax)

  # Neuron parameters
  # Each layer comprises a heterogenous set of neurons, with a small spread
  # of parameter values, so that they exhibit some dynamical variation
  # (To get a homogenous population of canonical "regular spiking" neurons,
  # multiply r by zero.)

  # Layer 0 (regular spiking)
  r = rn.rand(N0)
  net.layer[0].N = N0

  net.layer[0].gNa = (110.0 + r*20.0) * np.ones(N0)
  net.layer[0].gK = (35.0 + r*2.0) * np.ones(N0)
  net.layer[0].gL = 0.3 * np.ones(N0)

  net.layer[0].eNa = (111.0 + r*9) * np.ones(N0)
  net.layer[0].eK = -12.0
  net.layer[0].eL = 10.6


  # Layer 1 (regular spiking)
  r = rn.rand(N1)
  net.layer[1].N = N1

  net.layer[1].gNa = (110.0 + r*20) * np.ones(N1)
  net.layer[1].gK = (35.0 + r*2.0) * np.ones(N1)
  net.layer[1].gL = 0.3 * np.ones(N1)

  net.layer[1].eNa = (111.0 + r*9) * np.ones(N1)
  net.layer[1].eK = -12.0 * np.ones(N1)
  net.layer[1].eL = 10.6 * np.ones(N1)

  ## Connectivity matrix (synaptic weights)
  # layer[i].S[j] is the connectivity matrix from layer j to layer i
  # S(i,j) is the strength of the connection from neuron j to neuron i
  net.layer[1].S[0]      = np.ones([N1, N0])
  net.layer[1].factor[0] = F
  net.layer[1].delay[0]  = D * np.ones([N1, N0], dtype=int)

  return net
