class WordGen
	def initialize
		@folder = "outputs"
		@file_prefix = "files"
		@num_of_words = 100000
		@num_of_files = 100
		if ARGV[0] then 
			@num_of_words = ARGV[0].to_i
		end
		if ARGV[1] then 
			@num_of_files = ARGV[1].to_i
		end
	end
	#
	#	Generate a random word length between min and max
	#
	def genWord(max, min = 3)
		len = rand(max-min) + min
		#if len == 0 then puts "zero" end
		[*('a'..'z')].sample(len).join
	end
	#
	#	write @num_of_files files. Each file has @num_of_words
	#
	def writeFiles
		total = 0
		Dir.mkdir(@folder) unless File.exists?(@folder)
		1.upto(@num_of_files){|n|
			fname = @file_prefix + n.to_s.rjust(4, "0")
			fname = @folder + "/" + fname + ".txt"
			outp = File.open(fname, "w")
			num = rand((@num_of_words * 2)) + @num_of_words/2
				1.upto(num){|x|
		  			outp.print genWord(10)
		  			outp.print " "
		  			if x % 100 == 0 then outp.puts "\n" end 
		  		}
		  	 total += num
		  	puts num.to_s + " words in " + fname
			outp.close
		}
		puts "Total: #{total} words."
	end
end

w = WordGen.new
w.writeFiles
