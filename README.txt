+---------------+
| Penguin Fetch |
+---------------+

        Penguin (Fetch) is a light and quick alternative to ``neofetch`` written
        completely in C. Currently has extensive support for macOS (although
        most Linux distributions should be compatible). 

        LICENSE NOTICE

        Copyright (C) 2023 Wasif Kamran and Bob Yuan 

        This program is free software: you can redistribute it and/or modify
        it under the terms of the GNU General Public License as published by
        the Free Software Foundation, either version 3 of the License, or
        (at your option) any later version.

        This program is distributed in the hope that it will be useful,
        but WITHOUT ANY WARRANTY; without even the implied warranty of
        MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
        GNU General Public License for more details.

        You should have received a copy of the GNU General Public License
        along with this program.  If not, see <https://www.gnu.org/licenses/>.


HOW TO COMPILE 

Considering that the program won't compile on non-Unix systems, simply run 
``make`` will generate an executable called ``penguin``. Alternatively, complile 
the project as you would any C project - it's quite straightforward. 


HOW FAST IS IT 

Using David Peter's benchmarking tool, hyperfine (https://github.com/sharkdp/hyperfine), 
penguin has an average runtime of 8.6ms with a standard deviation of 6.1ms. For 
comparison, this is 63.93 ± 17.41 times faster than the traditional neofetch. 

The system used for benchmarking was a 2020 M1 MacBook Pro running Ventura
13.2.1 


WHAT INFORMATION IS SUPPORTED 

Currently the following information should be displayed upon running penguin: 

        • Kernel information and version 
        • OS name, version, architecture      
        • Shell 
        • Uptime 
        • Disk usage 
        • CPU name 
        • Machine model 
        • Terminal size 


ASCII penguin from https://ascii.co.uk/art/penguins by Axel Poque aka apx 
   _
 ('v')
//-=-\\
(\_=_/)
 ^^ ^^
