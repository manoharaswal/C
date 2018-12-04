///	Structures used by entry system to hold car related information.

struct entry_system {
	int car_no;		/// car registration number
	int token_id;		/// Auto generated token ID
	int time;		/// Entry time 
};

///	structure which is having additional information of driver.
struct driver_info {
	char name[32];		/// driver name
	char mom_name[32];	/// drivers mother name
	int token_id;		/// tokinid (work as unique id at the time of exit)
};

 ///	END OF STRUCT.H
