patientfees: Main.o Surgery.o Pharmacy.o PatientAccount.o
	g++ Main.o Surgery.o Pharmacy.o PatientAccount.o -o patientfees

Main.o: Main.cpp
	g++ -c Main.cpp

Surgery.o: Surgery.cpp Surgery.h
	g++ -c Surgery.cpp 

Pharmacy.o: Pharmacy.cpp Pharmacy.h
	g++ -c Pharmacy.cpp 

PatientAccount.o: PatientAccount.cpp PatientAccount.h
	g++ -c PatientAccount.cpp 

#for windows remove rm and switch to del
clean:
	del *.o patientfees patientfees.exe


run:
	./patientfees