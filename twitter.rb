require 'serialport'
require 'twitter'
require 'rubygems'


  client = Twitter::REST::Client.new do |config|
  config.consumer_key        = 'J9MyQ41IyVSHkXbqTXolzb4cx'
  config.consumer_secret     = 'gcHAGFcKDa9N0fWBnJEc26tETIAyZUxJhKwu5RO96GSsVdByuA'
  config.access_token        = '2686146270-gTQ3oghrRVjnmpb3xkLEVStducDjiQygSUFaM0b'
  config.access_token_secret = 'vu2aw5qyGgQWRYNIJvSzpk3x2OvWj2MzFzIGfXFrmJpS1'
end

#SerialPort
port_file = "/dev/ttyACM0"
baud_rate = 9600 
data_bits = 8
stop_bits = 1
parity = SerialPort::NONE
 
#create a SerialPort object using each of the bits of information
port = SerialPort.new(port_file, baud_rate, data_bits, stop_bits, parity)

while true do
	 while (l = port.gets) do       
      puts ('lugar '+l)
	client.update('Solo hay: '+l+' lugares disponibles en @ArduixCar')
    end
end

port.close
#client.update("I'm tweeting with @gem!")




