#! /usr/bin/env python3

import sys
import os.path
import zipfile
import subprocess

def text(file):
    string = file.replace('.', '_')
    return '\
<VirtualHost *:80>\n\
    DocumentRoot /var/www/http_' + string + '/web/www\n\
    ServerName www.' + file + '\n\
    ServerAlias *.' + file + '\n\
    VirtualDocumentRoot /var/www/http_' + string + '/%1\n\
    CustomLog /var/www/http_' + string + '/logs/access.log combined\n\
    ErrorLog /var/www/http_' + string + '/logs/error.log\n\
    <Directory \"/var/www/http_' + string + '/web/www/\">\n\
        Options -Indexes\n\
    </Directory>\n\
</VirtualHost>\n'

def main():
    print('Getting the first argument...')
    # Error checking for command line
    if len(sys.argv) < 2:
        print('ERROR: no input file')
        exit(2)
    # Vars
    string = sys.argv[1].replace('.', '_')
    apachedir = '/etc/apache2/site-available/'
    fname = apachedir + 'http_' + string
    zipname = '/var/www/default.zip'
    # Error checking
    if not os.path.exists(apachedir):
        print('ERROR: ' + apachedir + ' does not exist.')
        print('Make sure that apache is installed and retry.')
        exit(1)
    if os.path.exists(fname):
        print('ERROR: ' + fname + ' already exists')
        exit(1)
    if not os.path.exists(zipname):
        print('ERROR: ' + zipname + ' does not exist.')
        exit(1)
    # Create and open the specified file for writing
    with open(fname, 'w+') as f:
        f.write(text(sys.argv[1]))
    print(fname + ' successfully written.')
    # Unzip the log and error files
    print('Extracting...')
    zip = zipfile.ZipFile(zipname)
    path = '/var/www/http_' + string
    zip.extractAll(path)
    zip.close()
    print('Extraction successful to ' + path)
    # Executions
    print('Executing...')
    try:
        subprocess.call(["a2ensite", path], shell=True)
        subprocess.call("/etc/init.d/apache2 reload")
        print('Execution successful. Script will now end...')
        exit(0)
    except:
        print('ERROR: calling "a2ensite ' + path + '" or "/etc/init.d/apache2 reload" generated an error. Please ask the developper for infos.')

main()
