#include <iostream>
#include <boost/filesystem/fstream.hpp>
#include <boost/filesystem.hpp>
namespace fs = boost::filesystem;
#include <boost/program_options.hpp>
namespace po = boost::program_options;
#include <boost/foreach.hpp>

#include "boost/avloop.hpp"

int main(int argc, char* argv[])
{
	// command line options
	po::options_description desc_cmd("main options");
	desc_cmd.add_options()
		("version,v", "output version")
		("help,h", "output help msg")
		("daemon,d", "run at daemon mode")
	;

	po::variables_map vm_cmd;
	po::store(po::parse_command_line(argc, argv, desc_cmd), vm_cmd);
	po::notify(vm_cmd);

	// configure file options(INI FORMAT)
	std::string vkserverport;
	po::options_description desc_conf("conf options");
	desc_conf.add_options()
		("port", po::value<std::string>(&vkserverport)->default_value("2014"), "server port")
	;
	std::vector<fs::path> config_files;
	config_files.push_back("/etc/vkMain.conf");
	if (getenv("HOME")) {
		config_files.push_back(fs::path(getenv("HOME")) / ".vkMain.conf");
	}
	config_files.push_back(fs::path("./vkMain.conf"));
	po::variables_map vm_conf;
	//std::ifstream config_stream("vkMain.conf.bak");
	std::istringstream config_stream;
	po::store(po::parse_config_file<char>(config_stream, desc_conf, true), vm_conf);
	BOOST_FOREACH(const fs::path& config_file, config_files) {
		if (fs::exists(config_file)) {
			po::store(po::parse_config_file<char>(config_file.string().c_str(), desc_conf, true), vm_conf);
		}
	}
	//std::cout << "vkserverport: " << vkserverport << std::endl;
	po::notify(vm_conf);
	//std::cout << "vkserverport: " << vkserverport << std::endl;

	if (vm_cmd.count("help")) {
		std::cerr << desc_cmd << std::endl;
		return 1;
	}

	if (vm_cmd.count("version")) {
		std::cout << "0.1" << std::endl;
		exit(EXIT_SUCCESS);
	}

	boost::asio::io_service io_service;

	if (vm_cmd.count("daemon")) {
		io_service.notify_fork(boost::asio::io_service::fork_prepare);
		daemon(0, 0);
		io_service.notify_fork(boost::asio::io_service::fork_child);
		//init_native_syslog();
	} else {
		//start_stdinput(io_service);
		//connect_stdinput(boost::bind(stdin_feed_broadcast , boost::ref(mybot), _1));
	}

	avloop_run(io_service);

	return 0;
}

