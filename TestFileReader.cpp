#include "FileReader.cpp"

int main(int argc, char *argv[]){

    bool debug = false;

    if(argc != 3){
		std::cout<<"usage: "<< argv[0] <<" <filename> <debugmode(0 or 1)>\n";
		return 1;
	}else{
            if(*argv[2] == '1'){
                debug = true;
            }

             FileReader reader(argv[1], debug);

             reader.getTotalTicks();
             reader.getGreenTicks();
             reader.getYellowTicks();
             reader.getRedTicks();
    }
    return 0;
}