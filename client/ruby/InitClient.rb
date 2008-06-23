#!/usr/bin/ruby -w
# **zappy** -- InitClient.rb

require 'include.rb';

class InitClient
  def initialize()
    @_hostname = HOSTNAME;
    @_port = PORT;
    @_team = nil;
    @_leader = false;
  end

  def parseArgs(argv)
    i = 0;
    flag = 0;
    while (i < argv.length)
      case argv[i]
      when '-h'
        if (argv[i + 1])
          @_hostname = argv[i + 1];
          i += 1;
        else
          self.usage();
        end
      when '-p'
        if (argv[i + 1])
          @_port = argv[i + 1].to_i();
          i += 1;
        else
          return (0);
        end
      when '-t'
        if (argv[i + 1])
          flag |= FLAG_TEAM;
          @_team = argv[i + 1];
          i += 1;
        else
          return (0);
        end
      when '--leader'
        @_leader = true;
      when '--help'
        return (0);
      end
      i += 1;
    end

    if ((flag & FLAG_TEAM) == 0)
      return (0);
    else
      return (1);
    end
  end

  def usage(binary)
    print "usage: #{binary} [-h hostname] [-p port] -t team [--leader] [--help]\n";
    exit(EXIT_SUCC);
  end

  attr_accessor :_hostname;
  attr_accessor :_port;
  attr_accessor :_team;
  attr_accessor :_leader;
end
