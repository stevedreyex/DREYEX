var Map=function(){
	this.map = new Array();     
    for(i=0; i<27; i++){
        this.map[i] = new Array();
        for(j=0;j<15;j++){
            this.map[i][j]=0;
        }
    }
    this.M=60;
    this.len=0;
    this.rot=0;

    this.st_position={
        x:0,
        y:0
    }


    this.check= function(start_position_x,start_position_y,Len,Rot) {
        this.len=Len;
        this.rot=Rot;
        this.st_position={
            x:start_position_x,
            y:start_position_y
        }

        this.arrayPosition={                      //以this.position為基準對每一張貼出的圖像作偏移
            x:Math.round(this.st_position.x/160),
            y:Math.round(this.st_position.y/160)
        }

        this.pre_position={
            x:this.arrayPosition.x,
            y:this.arrayPosition.y
        }

        this.map[this.arrayPosition.x][this.arrayPosition.y]=1;

        for(j=1;j<this.len;j++){
            this.arrayPosition={                      //以this.position為基準對每一張貼出的圖像作偏移
                x:Math.round((this.st_position.x+(this.M*j)*Math.cos(this.rot*Math.PI/180))/160),
                y:Math.round((this.st_position.y+(this.M*j)*Math.sin(this.rot*Math.PI/180))/160)
            }

            if(!(this.pre_position.x==this.arrayPosition.x) || !(this.pre_position.y==this.arrayPosition.y)){
                if(this.map[this.arrayPosition.x][this.arrayPosition.y]==0){
                    this.map[this.arrayPosition.x][this.arrayPosition.y]=1;
                }
                else{
                    return j;
                }
            }

            this.pre_position=this.arrayPosition;
        }
        return this.len;  

    };


};