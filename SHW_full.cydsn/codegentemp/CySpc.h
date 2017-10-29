, see also Benchmark::CAPTION
    CAPTION = "      user     system      total        real\n"

    # Default format string, see also Benchmark::FORMAT
    FORMAT = "%10.6u %10.6y %10.6t %10.6r\n"

    # User CPU time
    attr_reader :utime

    # System CPU time
    attr_reader :stime

    # User CPU time of children
    attr_reader :cutime

    # System CPU time of children
    attr_reader :cstime

    # Elapsed real time
    attr_reader :real

    # Total time, that is _utime_ + _stime_ + _cutime_ + _cstime_
    attr_reader :total

    # Label
    attr_reader :label

    #
    # Returns an initialized Tms object which has
    # _utime_ as the user CPU time, _stime_ as the system CPU time,
    # _cutime_ as the children's user CPU time, _cstime_ as the children's
    # system CPU time, _real_ as the elapsed real time and _label_ as the label.
    #
    def initialize(utime = 0.0, stime = 0.0, cutime = 0.0, cstime = 0.0, real = 0.0, label = nil)
      @utime, @stime, @cutime, @cstime, @real, @label = utime, stime, cutime, cstime, real, label.to_s
      @total = @utime + @stime + @cutime + @cstime
    end

    #
    # Returns a new Tms object whose times are the sum of the times for this
    # Tms object, plus the time required to execute the code block (_blk_).
    #
    def add(&blk) # :yield:
      self + Benchmark.measure(&blk)
    end

    #
    # An in-place version of #add.
    #
    def add!(&blk)
      t = Benchmark.measure(&blk)
      @utime  = utime + t.utime
      @stime  = stime + t.stime
      @cutime = cutime + t.cutime
      @cstime = cstime + t.cstime
      @real   = real + t.real
      self
    end

    #
    # Returns a new Tms object obtained by memberwise summation
    # of the individual times for this Tms object with those of the other
    # Tms object.
    # This method and #/() are useful for taking statistics.
    #
    def +(other); memberwise(:+, other) end

    #
    # Returns a new Tms object obtained by memberwise subtraction
    # of the individual times for the other Tms object from those of this
    # Tms object.
    #
    def -(other); memberwise(:-, other) end

    #
    # Returns a new Tms object obtained by memberwise multiplication
    # of the individual times for this Tms object by _x_.
    #
    def *(x); memberwise(:*, x) end

    #
    # Returns a new Tms object obtained by memberwise division
    # of the individual times for this Tms object by _x_.
    # This method and #+() are useful for taking statistics.
    #
    def /(x); memberwise(:/, x) end

    #
    # Returns the contents of this Tms object as
    # a formatted string, according to a format string
    # like that passed to Kernel.format. In addition, #format
    # accepts the following extensions:
    #
    # <tt>%u</tt>::     Replaced by the user CPU time, as reported by Tms#utime.
    # <tt>%y</tt>::     Replaced by the system CPU time, as reported by #stime (Mnemonic: y of "s*y*stem")
    # <tt>%U</tt>::     Replaced by the children's user CPU time, as reported by Tms#cutime
    # <tt>%Y</tt>::     Replaced by the children's system CPU time, as reported by Tms#cstime
    # <tt>%t</tt>::     Replaced by the total CPU time, as reported by Tms#total
    # <tt>%r</tt>::     Replaced by the elapsed real time, as reported by Tms#real
    # <tt>%n</tt>::     Replaced by the label string, as reported by Tms#label (Mnemonic: n of "*n*ame")
    #
    # If _format_ is not given, FORMAT is used as default value, detailing the
    # user, system and real elapsed time.
    #
    def format(format = nil, *args)
      str = (format || FORMAT).dup
      str.gsub!(/(%[-+\.\d]*)n/) { "#{$1}s" % label }
      str.gsub!(/(%[-+\.\d]*)u/) { "#{$1}f" % utime }
      str.gsub!(/(%[-+\.\d]*)y/) { "#{$1}f" % stime }
      str.gsub!(/(%[-+\.\d]*)U/) { "#{$1}f" % cutime }
      str.gsub!(/(%[-+\.\d]*)Y/) { "#{$1}f" % cstime }
      str.gsub!(/(%[-+\.\d]*)t/) { "#{$1}f" % total }
      str.gsub!(/(%[-+\.\d]*)r/) { "(#{$1}f)" % real }
      format ? str % args : str
    end

    #
    # Same as #format.
    #
    def to_s
      format
    end

    #
    # Returns a new 6-element array, consisting of the
    # label, user CPU time, system CPU time, children's
    # user CPU time, children's system CPU time and elapsed
    # real time.
    #
    def to_a
      [@label, @utime, @stime, @cutime, @cstime, @real]
    end

    protected
    
    #
    # Returns a new Tms object obtained by memberwise operation +op+
    # of the individual times for this Tms object with those of the other
    # Tms object.
    #
    # +op+ can be a mathematical operation such as <tt>+</tt>, <tt>-</tt>,
    # <tt>*</tt>, <tt>/</tt>
    #
    def memberwise(op, x)
      case x
      when Benchmark::Tms
        Benchmark::Tms.new(utime.__send__(op, x.utime),
                           stime.__send__(op, x.stime),
                           cutime.__send__(op, x.cutime),
                           cstime.__send__(op, x.cstime),
                           real.__send__(op, x.real)
                           )
      else
        Benchmark::Tms.new(utime.__send__(op, x),
                           stime.__send__(op, x),
                           cutime.__send__(op, x),
                           cstime.__send__(op, x),
                           real.__send__(op, x)
                           )
      end
    end
  end

  # The default caption string (heading above the output times).
  CAPTION = Benchmark::Tms::CAPTION

  # The default format string used to display times.  See also Benchmark::Tms#format.
  FORMAT = Benchmark::Tms::FORMAT
end

if __FILE__ == $0
  include Benchmark

  n = ARGV[0].to_i.nonzero? || 50000
  puts %Q([#{n} times iterations of `a = "1"'])
  benchmark("       " + CAPTION, 7, FORMAT) do |x|
    x.report("for:")   {for _ in 1..n; _ = "1"; end} # Benchmark.measure
    x.report("times:") {n.times do   ; _ = "1"; end}
    x.report("upto:")  {1.upto(n) do ; _ = "1"; end}
  end

  benchmark do
    [
      measure{for _ in 1..n; _ = "1"; end},  # Benchmark.measure
      measure{n.times do   ; _ = "1"; end},
      measure{1.upto(n) do ; _ = "1"; end}
    ]
  end
end
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 