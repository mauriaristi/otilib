# ***************************************************************************************************
def report_times_in_file(times, filename="report.json"):

    import json

    mod = json.dumps(times,indent=2)
    f = open(filename,"w")
    f.write(mod)
    f.close()

# ---------------------------------------------------------------------------------------------------



# ***************************************************************************************************
def report_times_in_file_b(times, filename="report_times.dat"):

    import pickle
   
    f = open(filename,"wb")

    pickle.dump(times,f)

    f.close()

# ---------------------------------------------------------------------------------------------------