/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   main.cpp										   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: teando <teando@student.42tokyo.jp>		 +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/05/29 03:13:29 by teando			#+#	#+#			 */
/*   Updated: 2025/05/29 04:16:05 by teando		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

std::string ReplaceTxt(	const std::string &txt,
						const std::string &s1,
						const std::string &s2) {
	if (s1.empty() || s1 == s2)
		return txt;

	std::string ret;
	ret.reserve(txt.size());

	std::string::size_type pos = 0;
	std::string::size_type found;
	while ((found = txt.find(s1, pos)) != std::string::npos) {
		ret.append(txt, pos, found - pos);
		ret.append(s2);
		pos += found - pos + s1.length();
	}
	return ret.append(txt, pos, std::string::npos);
}

int main(int ac, char **av) {
	if (ac != 4) {
		std::cout << "Usage: " << av[0] << " <filename> <s1> <s2>" << std::endl;
		return 1;
	}

	std::string filename(av[1]);
	std::ifstream in(filename.c_str());
	if (!in) {
		std::cerr << "Cannot open input file: " << filename << std::endl;
		return 1;
	}
	std::ostringstream oss;
	oss << in.rdbuf();
	in.close();

	std::string replaced = ReplaceTxt(oss.str(), av[2], av[3]);

	std::ofstream out((filename + ".replace").c_str());
	if (!out) {
		std::cerr << "Cannot open output file: " << (filename + ".replace") << std::endl;
		return 1;
	}
	out << replaced;
	out.close();
	return 0;
}
