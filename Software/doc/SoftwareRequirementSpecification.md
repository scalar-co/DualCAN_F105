# Software Requirement Specification

## 1. Reference to hardware arhitecture

This ECU consists of:

- CAN channel 1

- CAN channel 2

- Serial communication with PC software

## 2. Requirements for software

### 2.1. UDS on Serial communication

SWR_ID_2.1.1

The ECU SW shall provide UDS on the serial communication.

SWR_ID_2.1.2

The ECU SW shall provide NVM for storage of functionality configurations.

SWR_ID_2.1.3

The ECU SW shall check if the functionalitiy configurations are avaiable and valid.

### 2.2. Exchange CAN frames

SWR_ID_2.2.1

The ECU SW shall be able to transfer CAN frames from channel 1 to channel 2, with customer specified transfer rules.

SWR_ID_2.2.2

The ECU SW shall be able to transfer CAN frames from channel 2 to channel 1, with customer specified transfer rules.

SWR_ID_2.2.3.1

The transfer rules shall be configurable via UDS protocol (Write by data ID).

SWR_ID_2.2.3.2

The transfer rules shall be stored in NVM.

SWR_ID_2.2.4.1

The transfer process shall be controlled via UDS protocal (Routine Control).

SWR_ID_2.2.4.2

The transfer process state (activated or deactivated) shall be stored in NVM.
i.e. User can configure whether the transfer process starts or not after every time POR.

### 2.3. Simulate CAN frames

SWR_ID_2.3.1

The ECU shall be able to simulate CAN frame transmission on channel 1, with customer specified CAN frame contents.

SWR_ID_2.3.2

The ECU shall be able to simulate CAN frame transmission on channel 2, with customer specified CAN frame contents.

SWR_ID_2.3.3.1

The CAN frame contents shall be configurable via UDS protocol (Write by data ID), and be stored in NVM

SWR_ID_2.3.3.2

The CAN frame contents shall be stored in NVM.

SWR_ID_2.3.4.1

The simulation process shall be controlled via UDS protocal (Routine Control).

SWR_ID_2.3.4.2

The simulation process state (activated or deactivated) shall be stored in NVM.
i.e. User can configure whether the simulation process starts or not after every time POR.
