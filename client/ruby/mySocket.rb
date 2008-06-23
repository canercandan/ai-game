#!/usr/bin/ruby -w
# **zappy** -- mySocket.rb

require 'socket';
include Socket::Constants;

class   MySocket
  def initialize(host, port)
    @_socket = -1;
    self.connectSocket(host, port);
  end

  def connectSocket(host, port)
    @_socket = Socket.new(AF_INET, SOCK_STREAM, 0);
    sockaddr = Socket.sockaddr_in(port, '127.0.0.1');
    @_socket.connect(sockaddr);
  end

  def closeSocket()
    @_socket.close;
    @_socket = -1;
  end

  def send(mesg)
    if (!self.isConnected())
      $stderr.print "error: MySocket.send - not connected\n";
    end
    @_socket.send(mesg, 0);
  end

  def recv()
    if (!self.isConnected())
      $stderr.print "error: MySocket.recv - not connected\n";
    end
    buff = @_socket.recvfrom(BUFF_SIZE);
    return (buff.to_s);
  end

  def recvNoBlk()
    if (!self.isConnected())
      $stderr.print "error: MySocket.recvNoBlk - not connected\n";
    end
    buff = self._socket.recvfrom_nonblock(BUFF_SIZE);
    return (buff.to_s);
  end

  def isConnected()
    return (@_socket == -1 ? false : true);
  end

  attr_accessor :_socket;
end
