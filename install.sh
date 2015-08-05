#! /bin/sh

# TODO: INSTALL MYSQL AND POSTGRESQL

# Oh my zsh
#sudo apt-get install zsh
#chsh -s /usr/bin/zsh
#sh -c "$(wget https://raw.github.com/robbyrussell/oh-my-zsh/master/tools/install.sh -O -)"
zsh --version >> setup.log

# Java
#sudo add-apt-repository ppa:webupd8team/java
#sudo apt-get update
#sudo apt-get install oracle-java8-installer
java -version >> setup.log

### Install hidden files and directories ###

# Composer (for PHP and Laravel framework)
curl -sS https://getcomposer.org/installer | php
cd /usr/bin && ln -s $OLDPWD/composer.phar composer

# Git
echo 'Installing git...' >> setup.log
#sudo apt-get install git && echo 'Installed git' >> setup.log || exit 1

# Clone configs repo
echo 'Cloning configs repo from bitbucket...' >> setup.log
#git clone https://Inadvertance@bitbucket.org/Inadvertance/configs.git

cd $HOME && echo "Going to $HOME..." >> setup.log
# Loop over files
for file in $(ls -a $OLDPWD); do
  case "$file" in
    ".git")         echo "Ignoring .git";;
    ".gitignore")   echo "Ignoring .gitignore";;
    "$0")           echo "Ignoring $0";;
    # Make symlinks from git repository to $HOME
    *)              ln -s "$OLDPWD/$file";;
  esac
done

echo "----- TODO -----"
echo "Install IntelliJIdea"
echo "Install Gimp"
echo "Reload fonts to take ~/.fonts/Monaco into account"
echo "Setup ssh"
echo "----- Optionals -----"
echo "Retrieve lessons and projects from bitbucket repositories"
echo "Install i3 (if necessary)"
echo "Get an image background"
echo "Install Brackets"
