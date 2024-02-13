twitchcap
=========

![Demo image 1](/resources/demo1.png)

![Demo image 2](/resources/demo2.png)

### Overview

Twitchcap (short for Twitch capture) is a tool that logs into a Twitch IRC
channel and shows the raw output from Twitch. This tool includes functionality
to request specific extensions (tags, membership, and commands), as well as
the ability to send messages to a channel.

Twitchcap demonstrates how to connect to a Twitch IRC channel using only Qt's
QTcpSocket and C++.

### Usage

Twitchcap does not take options over the command-line. You **must** supply an
oauth token for the password. To generate an oauth token, go here:
[https://twitchapps.com/tmi/](https://twitchapps.com/tmi/). Note that this
website is a third-party website.

### Why

**Example Project**: This project was designed to be a baseline for creating a
bot that connects to Twitch using Qt and C++. As a result, the design is very
basic to make it easier to modify.

**Bot Building**: I'm hoping that this tool showing the raw output from Twitch
will help with building Twitch bots.
