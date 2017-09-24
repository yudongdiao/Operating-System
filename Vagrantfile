Vagrant.configure("2") do |config|
  config.vm.box = "bento/ubuntu-16.04"

  config.vm.provider "virtualbox" do |vb|
   vb.gui = true
  end
  config.vm.provision "shell", inline: <<-SHELL
    sudo add-apt-repository ppa:webupd8team/atom
    apt-get update
    apt-get upgrade
    apt-get install -y wget curl atom build-essential emacs git cmake libgtest-dev python zip gdb

    # Uncomment if you want a full blow desktop environment (takes a long time)
    apt-get install -y ubuntu-desktop
  SHELL
end