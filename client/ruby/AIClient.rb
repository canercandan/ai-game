#!/usr/bin/ruby -w
# **zappy** -- AIClient.rb

require 'include.rb';

class   AIClient
  def initialize(sck, team, leader)
    @_sck = sck;
    @_team = team;
    @_leader = leader;
  end

  def enterInTheWorld()
    mesg = self.doAction(SEND, @_team);
    if (mesg.match(/ko/))
      $stderr.print "The name of your team doesn't exist!!\n";
      exit(EXIT_FAIL);
    end
    mesg = mesg.split("\n");
    return (mesg[0].to_i());
  end

  def loopAction()
    @_rock = {
      "linemate"        => 0,
      "deraumere"       => 0,
      "sibur"           => 0,
      "mendiane"        => 0,
      "phiras"          => 0,
      "thystame"        => 0
    };
    @_find = false;
    self.printMessage(">> Hi, I'm a Trantorien and my team is [#{@_team}]");
    if (@_leader == true)
      self.printMessage(">> I'm the leader of my team^^");
    end
    self.initRock();
    self.initLevel();
    while (@_level != 8)
      if (!self.enoughHp())
        self.searchFood();
      else
        self.searchRock();
      end
    end
  end

  def initRock()
    mesg = self.doAction(INVENTORY);
    inv = mesg.split(',');
    len = inv.length() - 1;
    for i in 1..len
      s = inv[i];
      name = s[/(\w+)/];
      nb = s[/(\d+)/];
      @_rock[name] = nb.to_i();
    end
  end

  def initLevel()
    print "INIT LEVEL";
    mesg = self.doAction(LOOK);
    mesg = mesg.split(',');
    len = mesg.length() - 1;
    lvl = 0;
    i = 1;
    while (i < len)
      lvl += 1;
      i += i + 2;
    end
    @_level = lvl;
  end

  def enoughHp()
    mesg = self.doAction(INVENTORY);
    print "mesg = #{mesg}\n";
    inv = mesg.split(',');
    hp = inv[0][/(\d+)/].to_i;
    return (hp > UNIT_MINI ? true : false);
  end

  def enoughRock()
    @_rock.each() {
      |key, value|;
      if (value < NbRockPerLevel[key][@_level - 1])
        return (key);
      end
    };
    return (nil);
  end

  def searchFood()
    self.printMessage(">> I SEARCH SOME FOOD");
    self.findRessources(FOOD);
  end

  def searchRock()
    rock = self.enoughRock();
    if (rock == nil)
      self.goToLevelUp();
    else
      self.findRessources(rock);
    end
  end

  def findRessources(res)
    self.printMessage(">> I SEARCH #{res} BECAUSE I NEED IT");
    find = false;
    while (find == false)
      mesg = self.doAction(LOOK);
      mesg = mesg.split(',');
      i = 0;
      mesg.each() do
        |zone|;
        if (zone.match(res))
          self.printMessage(">> I FIND '#{res}' IN CASE [#{i}]");
          self.moveToZone(i);
          self.doAction(TAKE, res);
          if (res != FOOD)
            @_rock[res] += 1;
          end
          find = true;
          break;
        end
        i += 1;
      end
      if (find == false)
        self.move();
      end
    end
  end

  def move()
    begin
      alea = rand(3);
      print "alea = #{alea}\n";
      self.doAction(alea);
    end while (alea != UP)
  end

  def goToLevelUp()
    self.printMessage(">> I'M GOING TO LEVEL UP (MY LEVEL IS #{@_level})");
    nbPlayers = NbPlayerPerLevel[@_level - 1] - 1;
    self.goToIdealCase();
    if (nbPlayers == 0)
      self.myEvolution();
    else
      self.findTrantoriens(nbPlayers);
    end
  end

  def goToIdealCase()
  end

  def findTrantoriens(nbPlayers)
    nbBroadcast = MAX_BROADCAST;
    self.printMessage(">> I BROADCAST THE OTHERS TRANTORIENS, I NEED #{nbPlayers} PLAYER(S)\n");
    while (nbPlayers > 0 && (nbBroadcast != 0))
      print "NB = #{nbBroadcast}\n";
      mesg = self.doAction( BROADCAST, "(BROADCAST){INCANTATION} I'm level [#{@_level}], I need you!!!");
      if (mesg.match(/[arrive]/))
        nbBroadcast += 1;
        self.printMessage(">> A FRIEND IS COMING TO HELP ME");
        mesg = mesg.split(',');
        level = mesg[1][/(\d+)/].to_i();
        nbPlayers = (@_level == level ? nbPlayers - 1 : nbPlayers);
      else
        nbBroadcast -= 1;
      end
    end
    self.myEvolution();
  end

  def myEvolution()
    tmp = {
      "linemate"        => 0,
      "deraumere"       => 0,
      "sibur"           => 0,
      "mendiane"        => 0,
      "phiras"          => 0,
      "thystame"        => 0
    };
    mesg = self.doAction(LOOK);
    floor = mesg.split(',');
    floor = floor[0].split(' ');
    len = floor.length() - 1;
    player = 0;
    for i in 0..len
      res = floor[i][/(\w+)/];
      print "res = #{res}\n";
      if (res == FOOD)
        self.doAction(TAKE, FOOD)
      elsif (res == "joueur")
        player += 1;
      else
        tmp[res] += 1;
      end
    end
    if (player == NbPlayerPerLevel[@_level - 1])
      self.takeAndDrop(tmp);
      mesg = self.doAction(INCANTATION);
      mesg = self.recvMessage();
      if (mesg.match(/ko/))
        self.printMessage(">> MY INCANTATION FAILED T__T");
      else
        @_level += 1;
      end
    end
  end

  def takeAndDrop(tmp)
    tmp.each() do
      |key, value|;
      diff = value - NbRockPerLevel[key][@_level - 1];
      if (diff > 0)
        diff.times() do
          self.doAction(TAKE, key);
          @_rock[key] += 1;
        end
      elsif (diff < 0)
        diff *= -1;
        diff.times() do
          self.doAction(DROP, key);
          @_rock[key] -= 1;
        end
      end
    end
  end

  def askLeader()
    mesg = self.doAction(BROADCAST, "(BROADCAST){LEADER} How many players are level [#{@_level}]?");
    begin
      mesg = self.waitMessage(nil);
    end while (mesg == nil)
    print "mesg leader = #{mesg}\n";
    exit(42);
  end

  def moveToZone(zone)
    if (zone == 0)
      return;
    end

    up = 1;
    add = 1;
    left = 1;
    middle = 2;
    right = 3;

    for i in 1..zone
      if (i > right)
        up += 1;
        add += 2;
        left += add;
        middle += add + 1;
        right += add + 2;
      end
    end

    for i in 0..(up - 1)
      self.doAction(UP);
    end

    if (zone == middle)
      return;
    end

    if (zone < middle)
      self.doAction(LEFT);
      (middle - zone).times do
        self.doAction(UP);
      end
    elsif (zone > middle)
      self.doAction(RIGHT);
      (zone - middle).times do
        self.doAction(UP);
      end
    end
  end

  def moveToDirection(direction)
    print "DIRECTION = #{direction}\n";
    case direction
    when 0
      mesg = self.doAction(BROADCAST, "(BROADCAST){RESPONSE} I [arrive] and my level is [#{@_level}]");
      while (!mesg.match(/niveau/))
        begin
          mesg = @_sck.recvNoBlk();
        rescue Errno::EAGAIN
          mesg = "wait";
          next;
        end
      end
      if (mesg.match(/niveau/))
        @_level += 1;
        self.loopAction();
      end
    when 1
      mesg = self.doAction(UP);
      d = 1;
    when 2
      mesg = self.doAction(UP);
      mesg = self.doAction(LEFT);
      d = 8;
    when 3
     mesg =  self.doAction(LEFT);
      d = 1;
    when 4
      mesg = self.doAction(LEFT);
      d = 2;
    when 5
      mesg = self.doAction(LEFT);
      mesg = self.doAction(LEFT);
      d = 1;
    when 6
      mesg = self.doAction(RIGHT);
      d = 8;
    when 7
      mesg = self.doAction(RIGHT);
      d = 1;
    when 8
      mesg = self.doAction(UP);
      mesg = self.doAction(RIGHT);
      d = 2;
    end
    @_find = true;
    mesg = self.doAction(LOOK);
    mesg = mesg.split(',');
    player = 0;
    mesg[0].each(' ') do
      |s|;
      print "s = #{s}\n";
      if (s.match("joueur"))
        player += 1;
      end
    end
    if (player == NbPlayerPerLevel[@_level - 1])
      d = 0;
    end
    self.moveToDirection(d);
  end

  def doAction(action, text = nil)
    case action
    when UP
      print "[send] --> #{ActionsName[UP]}\n";
      @_sck.send("#{ActionsName[UP]}\n");
    when RIGHT
      print "[send] --> #{ActionsName[RIGHT]}\n";
      @_sck.send("#{ActionsName[RIGHT]}\n");
    when LEFT
      print "[send] --> #{ActionsName[LEFT]}\n";
      @_sck.send("#{ActionsName[LEFT]}\n");
    when LOOK
      print "[send] --> #{ActionsName[LOOK]}\n";
      @_sck.send("#{ActionsName[LOOK]}\n");
    when INVENTORY
      print "[send] --> #{ActionsName[INVENTORY]}\n";
      @_sck.send("#{ActionsName[INVENTORY]}\n");
    when TAKE
      print "[send] --> #{ActionsName[TAKE]}: #{text}\n";
      @_sck.send("#{ActionsName[TAKE]} #{text}\n");
    when DROP
      print "[send] --> #{ActionsName[DROP]}: #{text}\n";
      @_sck.send("#{ActionsName[DROP]} #{text}\n");
    when EXPULSE
      print "[send] --> #{ActionsName[EXPULSE]}\n";
      @_sck.send("#{ActionsName[EXPULSE]}\n");
    when BROADCAST
      print "[send] --> #{ActionsName[BROADCAST]}: #{text}\n";
      @_sck.send("#{ActionsName[BROADCAST]} #{text}\n");
    when INCANTATION
      print "[send] --> #{ActionsName[INCANTATION]}\n";
      @_sck.send("#{ActionsName[INCANTATION]}\n");
    when FORK
      print "[send] --> #{ActionsName[FORK]}\n";
      @_sck.send("#{ActionsName[FORK]}\n");
    when SEND
      print "[send] --> #{text}\n";
      @_sck.send("#{text}\n");
    else
      return (nil);
    end
    mesg = self.recvMessage();
    return (mesg);
  end

  def recvMessage()
    print "waiting...\n";
    mesg = @_sck.recv();
    if (mesg.match(/mort/))
      self.printMessage(">> THANK YOU FOR ALL [DIE ANOTHER DAY !!!]");
      exit(EXIT_SUCC);
    elsif (mesg.match(/(BROADCAST)/))
      if (@_find == false)
        self.printMessage(">> I INTERCEPT BROADCAST: #{mesg}");
        if (!mesg.match(/RESPONSE/))
          self.actionBroadcast(mesg);
        end
      end
      mesg = self.recvMessage();
    end
    self.printMessage("[server] <-- #{mesg}");
    return (mesg);
  end

  def actionBroadcast(mesg)
    if (mesg.match(/INCANTATION/))
      mesg = mesg.split(',');
      print "mesg[0] = #{mesg[0]}\n";
      print "mesg[1] = #{mesg[1]}\n";
      direction = mesg[0][/(\d+)/].to_i();
      level = mesg[1][/(\d+)/].to_i();
      print "his level is #{level} (#{@_level}}), direction = #{direction}\n";
      if (@_level == level)
        self.printMessage(">> I FIND A DRONE WHO NEED SOME HELP !!");
        @_find = true;
        self.moveToDirection(direction);
      end
    end
  end

  def waitMessage(mesg)
    if (mesg.match(/ok/))
      begin
        mesg = @_sck.recvNoBlk();
      rescue Errno::EAGAIN
        retry;
      end
    end
    if (mesg.match(/LEADER/))
      return (mesg);
    else
      return ("ok");
    end
  end

  def printMessage(mesg)
    print "#{mesg}\n";
  end

  attr_accessor :_sck;
  attr_accessor :_level;
  attr_accessor :_team;
  attr_accessor :_rock;
  attr_accessor :_find;
end
