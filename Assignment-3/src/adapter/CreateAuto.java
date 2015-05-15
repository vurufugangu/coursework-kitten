/*
 * CIS 35B
 * Author: Wolfgang C. Strack
 * OS/Compiler: Windows 8/Java 8 with Eclipse
 * 
 * This is the CreateAuto interface.
 */
package adapter;

import util.AutoException;

public interface CreateAuto {
	public void buildAuto(String filename) throws AutoException;
	
	public void printAuto(String modelName);
	
	public boolean addOptionSet(
			String autoMake,
			String autoModel,
			String newOptionSetName);
	public boolean addOption(
			String autoMake,
			String autoModel,
			String optionSetName,
			String newOptionName,
			float newOptionPrice);
}
