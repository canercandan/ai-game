#!/usr/bin/ruby -w
# **zappy** -- AIClient.rb

#
## ~ Defines:
 #
EXIT_SUCC       = 42;
EXIT_FAIL       = 00;

HOSTNAME        = 'localhost';
PORT            = 12345;
FLAG_NAME       = 1;
FLAG_TEAM       = 2;

BUFF_SIZE       = 1024;
UNIT_INIT       = 1260;
UNIT_MINI       = 77;
NB_ACTION       = 5;
MAX_BROADCAST   = 5;

# class Enum
UP            = 0;
RIGHT         = 1;
LEFT          = 2;
LOOK          = 3;
INVENTORY     = 4;
TAKE          = 5;
DROP          = 6;
EXPULSE       = 7;
BROADCAST     = 8;
INCANTATION   = 9;
FORK          = 10;
SEND          = 42;
FOOD          = "nourriture";

# end

#
## ~ Tables:
 #

NbPlayerPerLevel = [1, 2, 2, 4, 4, 6, 6];

NbRockPerLevel = {
  "linemate"    => [1, 1, 2, 1, 1, 1, 2],
  "deraumere"   => [0, 1, 0, 1, 2, 2, 2],
  "sibur"       => [0, 1, 1, 2, 1, 3, 2],
  "mendiane"    => [0, 0, 0, 0, 3, 0, 2],
  "phiras"      => [0, 0, 2, 1, 0, 1, 2],
  "thystame"    => [0, 0, 0, 0, 0, 0, 1]
};

ActionsName = [
               "avance",
               "droite",
               "gauche",
               "voir",
               "inventaire",
               "prendre",
               "poser",
               "expulse",
               "broadcast",
               "incantation",
               "fork"
              ];

#
## ~ Require:
 #
require 'mySocket.rb';
require 'AIClient.rb';
require 'InitClient.rb';

# TODO: message = ko --> retry...
