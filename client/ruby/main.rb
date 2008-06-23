#!/usr/bin/ruby -w
# **zappy** -- main.rb

require 'include.rb';

client = InitClient.new();
if (client.parseArgs(ARGV) == 0)
  client.usage($0);
end

sck = MySocket.new(client._hostname, client._port);
print sck.recv();
if (sck.isConnected())
  player = AIClient.new(sck, client._team, client._leader);
  nbConnect = player.enterInTheWorld();
  nbConnect.times do
    fork do
      sck = MySocket.new(client._hostname, client._port);
      player = AIClient.new(sck, client._team, false);
      player.enterInTheWorld();
      player.loopAction();
    end
  end
end
