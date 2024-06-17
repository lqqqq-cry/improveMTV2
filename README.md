# improveMTV2

# How to generate data files?
## Run generate.sh
- Use this command: `sudo [Path_to_generate.sh] [SF] [Path_to_the_dir_of_data_files]`
- For example: `sudo ./generate.sh 0.05 ~/Downloads/improveMTV2/data/SF0.01`
- Output:
several output until "End generate files."

# How to load data files into MySQL?
## Run initializeSQL.sh
- Use this command: `sudo [Path_to_initializeSQL.sh] [Path_to_the_dir_of_data_files]`
- For example: `sudo ~/Downloads/improveMTV2/initializeSQL.sh ~/Downloads/improveMTV2/data/SF0.01`
- Output: 
Copy SSB tables to MySQL secure folder /var/lib/mysql-files/.
sudo cp /home/lia/Downloads/improveMTV2/data/SF0.01/lineorder.tbl /var/lib/mysql-files/lineorder.tbl
Sign in MySQL...
mysql: [Warning] Using a password on the command line interface can be insecure.
End load tables into MySQL.