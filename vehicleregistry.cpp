// File:        vehicleregistry.cpp
// Author:      Jason Park
// Date:        2015-05-24
// Description: Implementation of a VehicleRegistry class to be used for CMPT 225 assignment #1

#include "vehicleregistry.h"

///////////////////////////////
// Constructors / Destructor //
///////////////////////////////

// Default constructor
// Creates an empty VehicleRegistry with default array size (4)
VehicleRegistry::VehicleRegistry()
{
	numvehicles = 0;
	maxsize = 3;
	vehicles = new Vehicle[maxsize];
}


// Copy constructor
// Creates a new VehicleRegistry object,
// performs a deep copy of the vr parameter's fields
void VehicleRegistry::CopyArray(const VehicleRegistry& vr)
{
	maxsize = 3;
	vehicles = new Vehicle[maxsize];
	for (int i = 0; i < maxsize; i++)
	{
		vehicles[i] = vr.vehicles[i]; //performs a deep copy of dynamic array memory elements
		numvehicles++;
	}
}

// Destructor
// Releases all memory allocated to private pointer members
VehicleRegistry::~VehicleRegistry()
{
	delete[] vehicles;
}

//////////////////////////
// Mutators / Accessors //
//////////////////////////

// Insert - performs a set insertion with the vehicle registry
// Inserts vehicle and returns true if vehicle is not already in the registry
// Does not insert and returns false if a vehicle with a matching license plate
//   (only license plate needs to match) already exists in the registry
// If the array is already filled before the insertion occurs, then
//   first create a new dynamic array double the size of the old array,
//   copy all vehicle objects from old array to new array,
//   deallocate memory associated with the old array,
//   and insert the new vehicle and return true.
// POST:  registry contains vehicle
// PARAM: vehicle = item to be inserted, its fields should not be empty string
// NOTE:  since overloaded assignment operator has not been defined,
//          "insertion" will mean updating all fields of the vehicle at the appropriate index
bool VehicleRegistry::Insert(Vehicle vehicle)
{
	string tempStore = ""; 
	tempStore = vehicle.GetPlate();

	for (int i = 0; i < maxsize; i++)
	{
		if (tempStore == vehicles[i].GetPlate()) //checking whether the vehicle plate is already in the array
		{
			return false;
		}
		else
		{
			break;
		}
	}
	if (numvehicles == maxsize) //when vehicle registry is full perform a deeep copy and double the size of array
	{
		//VehicleRegistry newVR;
		//newVR.CopyArray(vehicle); don't understand why this isn't the same type of operation as below
		Vehicle* oldVehicles = vehicles;
		maxsize = 2 * maxsize;				
		vehicles = new Vehicle[maxsize];
		for (int i = 0; i < maxsize; i++)
		{
			vehicles[i] = oldVehicles[i];
		}
		delete[] oldVehicles;
	}
		//insert new vehicle and return true
		vehicles[numvehicles] = vehicle;
		numvehicles++;
		return true;
}


// Remove - performs a set removal with the vehicle registry
// Removes a vehicle with all matching parameters if one exists in the registry
// Returns false if a vehicle with the same parameters does not exist in the registry
// POST:  set does not contain vehicle
// PARAM: vehicle = item to be removed, its fields should not be empty string
// NOTE:  "removal" if successful will be done by updating the parameters of the
//          vehicle at the appropriate index using the parameters of the vehicle in
//          the last valid index of the collection; then decrements count and returns true;
bool VehicleRegistry::Remove(Vehicle vehicle)
{
	int found = Find(vehicle);
	if (found != -1) //if the vehicle is found then remove
	{
		//removes from the index and adjusts it accordingly
	}
	else
	{
		return false;
	}

}

// Locates the array index of a vehicle with matching license plate
// Returns -1 if no vehicle with matching license plate exists in the registry
// PARAM: vehicle = item to be located, its fields should not be empty string
int VehicleRegistry::Find(Vehicle vehicle)const
{
	string tempStore = "";
	tempStore = vehicle.GetPlate();
	for (int i = 0; i < maxsize; i++)
	{
		if (tempStore == vehicles[i].GetPlate()) //checking whether the vehicle plate is already in the array
		{
			return i;
		}
		else
		{
			continue;
		}
	}
	return -1;
}

// Returns the number of vehicles in the registry
int VehicleRegistry::Count() const
{
	return numvehicles;
}

////////////////////
// Set operations //
////////////////////

// Returns the set union of this and vr
// If both registries contain entries with identical license plate,
//   the parameters for the vehicle from the calling registry will take precedence.
// POST: union contains vehicles of this and vr, with no duplicate license plates.
VehicleRegistry Join(const VehicleRegistry& vr) const;

// Returns the set intersection of this and vr
// If both registries contain entries with identical license plate,
//   the parameters for the vehicle from the calling registry will take precedence.
// POST: intersection contains vehicles in both this and vr.
VehicleRegistry Common(const VehicleRegistry& vr) const;

// Returns the set difference of this and vr
// Vehicles in both registries must have a full set of matching parameters
//   for a vehicle to be removed in the split.
// POST: difference contains vehicles in this but not also in vr
VehicleRegistry Split(const VehicleRegistry& vr) const;
