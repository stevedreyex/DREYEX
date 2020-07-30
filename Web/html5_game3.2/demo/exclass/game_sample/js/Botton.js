var Botton=function(BW,BH){
	
    this.bottonW=BW;   //設定按鈕寬度
    this.bottonH=BH;   //設定按鈕長度

    this.load=function(BX,BY){    //設定按鈕最左上角位置
        this.bottonX=BX;
        this.bottonY=BY;



	};

    this.click=function(e){
        this.previousTouch = { x: e.x, y: e.y };
        if (this.previousTouch.x > this.bottonX && this.previousTouch.x < this.bottonX+this.bottonW && this.previousTouch.y > this.bottonY && this.previousTouch.y < this.bottonY+this.bottonH) {
            return true;
        }
    }




};