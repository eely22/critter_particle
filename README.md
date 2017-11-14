
Critter Particle
==========

This project contains the code necessary for setting up the bluz DK device via the Particle Web IDE and for configuring
the Webhooks in the particle cloud.

### Webhooks

There are two webhooks, one to capture voltage events and another for trap triggered events. The webhooks are ready to
go as-is, except that we obscured our API Key to our API endpoint. In order for this to work, you must get the API
key you specified in your Kinesis API (or leave it out altogether if you turned off API Keys).

For more information about how to post these to Particle, please view the
[Webhook documentation](https://docs.particle.io/reference/webhooks/).

### Bluz Firmware

The firmware folder contains the firmware file needed for bluz DK to act as a trap. This file can be flashed to bluz via
the Particle Web IDE. For more instructions, please visit the [bluz documentation](http://docs.bluz.io/) to get started.



