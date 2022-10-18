  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 3;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (test_P)
    ;%
      section.nData     = 104;
      section.data(104)  = dumData; %prealloc
      
	  ;% test_P.CompareToConstant1_const
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% test_P.CompareToConstant_const
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% test_P.Constant_Value
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% test_P.Constant_Value_c
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% test_P.Constant1_Value
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% test_P.Out1_Y0
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% test_P.Out2_Y0
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% test_P.DiscreteTimeIntegrator_gainval
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% test_P.DiscreteTimeIntegrator_IC
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% test_P.DiscreteTimeIntegrator1_gainval
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% test_P.DiscreteTimeIntegrator1_IC
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% test_P.DiscreteTimeIntegrator2_gainval
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% test_P.DiscreteTimeIntegrator2_IC
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% test_P.DiscreteTimeIntegrator3_gainval
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% test_P.DiscreteTimeIntegrator3_IC
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% test_P.DiscreteTimeIntegrator4_gainval
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% test_P.DiscreteTimeIntegrator4_IC
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% test_P.DiscreteTimeIntegrator5_gainval
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 17;
	
	  ;% test_P.DiscreteTimeIntegrator5_IC
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 18;
	
	  ;% test_P.DiscreteTimeIntegrator10_gainva
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 19;
	
	  ;% test_P.DiscreteTimeIntegrator10_IC
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 20;
	
	  ;% test_P.DiscreteTimeIntegrator11_gainva
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 21;
	
	  ;% test_P.DiscreteTimeIntegrator11_IC
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 22;
	
	  ;% test_P.DiscreteTimeIntegrator12_gainva
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 23;
	
	  ;% test_P.DiscreteTimeIntegrator12_IC
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 24;
	
	  ;% test_P.DiscreteTimeIntegrator13_gainva
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 25;
	
	  ;% test_P.DiscreteTimeIntegrator13_IC
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 26;
	
	  ;% test_P.DiscreteTimeIntegrator14_gainva
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 27;
	
	  ;% test_P.DiscreteTimeIntegrator14_IC
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 28;
	
	  ;% test_P.DiscreteTimeIntegrator6_gainval
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 29;
	
	  ;% test_P.DiscreteTimeIntegrator6_IC
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 30;
	
	  ;% test_P.DiscreteTimeIntegrator7_gainval
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 31;
	
	  ;% test_P.DiscreteTimeIntegrator7_IC
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 32;
	
	  ;% test_P.DiscreteTimeIntegrator8_gainval
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 33;
	
	  ;% test_P.DiscreteTimeIntegrator8_IC
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 34;
	
	  ;% test_P.DiscreteTimeIntegrator9_gainval
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 35;
	
	  ;% test_P.DiscreteTimeIntegrator9_IC
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 36;
	
	  ;% test_P.MPU6050Bias_Y0
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 37;
	
	  ;% test_P.MPU9250Bias_Y0
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 38;
	
	  ;% test_P.Gain_Gain
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 39;
	
	  ;% test_P.Gain1_Gain
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 40;
	
	  ;% test_P.EulerAngles_Y0
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 41;
	
	  ;% test_P.AccelI_Y0
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 42;
	
	  ;% test_P.Gain_Gain_l
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 43;
	
	  ;% test_P.Gain_Gain_d
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 44;
	
	  ;% test_P.Gain_Gain_n
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 45;
	
	  ;% test_P.Delay_InitialCondition
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 46;
	
	  ;% test_P.Delay1_InitialCondition
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 47;
	
	  ;% test_P.Delay2_InitialCondition
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 48;
	
	  ;% test_P.Gain1_Gain_o
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 49;
	
	  ;% test_P.Delay_InitialCondition_f
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 50;
	
	  ;% test_P.Delay1_InitialCondition_p
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 51;
	
	  ;% test_P.Delay2_InitialCondition_l
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 52;
	
	  ;% test_P.Gain2_Gain
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 53;
	
	  ;% test_P.I2CMasterRead_SampleTime
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 54;
	
	  ;% test_P.I2CMasterRead1_SampleTime
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 55;
	
	  ;% test_P.I2CMasterRead2_SampleTime
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 56;
	
	  ;% test_P.I2CMasterRead3_SampleTime
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 57;
	
	  ;% test_P.I2CMasterRead4_SampleTime
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 58;
	
	  ;% test_P.I2CMasterRead5_SampleTime
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 59;
	
	  ;% test_P.Constant3_Value
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 60;
	
	  ;% test_P.Constant4_Value
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 61;
	
	  ;% test_P.Constant6_Value
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 62;
	
	  ;% test_P.Constant7_Value
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 63;
	
	  ;% test_P.Constant_Value_a
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 64;
	
	  ;% test_P.Constant1_Value_a
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 65;
	
	  ;% test_P.I2CMasterRead_SampleTime_e
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 66;
	
	  ;% test_P.I2CMasterRead1_SampleTime_c
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 67;
	
	  ;% test_P.I2CMasterRead2_SampleTime_i
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 68;
	
	  ;% test_P.I2CMasterRead3_SampleTime_m
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 69;
	
	  ;% test_P.I2CMasterRead4_SampleTime_h
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 70;
	
	  ;% test_P.I2CMasterRead5_SampleTime_h
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 71;
	
	  ;% test_P.Constant3_Value_a
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 72;
	
	  ;% test_P.Constant4_Value_f
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 73;
	
	  ;% test_P.Constant6_Value_a
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 74;
	
	  ;% test_P.Constant7_Value_i
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 75;
	
	  ;% test_P.Constant_Value_d
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 76;
	
	  ;% test_P.Constant1_Value_n
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 77;
	
	  ;% test_P.MPU9250_SampleTime
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 78;
	
	  ;% test_P.Pitch_desired_Value
	  section.data(80).logicalSrcIdx = 79;
	  section.data(80).dtTransOffset = 79;
	
	  ;% test_P.RateTransition_InitialCondition
	  section.data(81).logicalSrcIdx = 80;
	  section.data(81).dtTransOffset = 80;
	
	  ;% test_P.DeadZone_Start
	  section.data(82).logicalSrcIdx = 81;
	  section.data(82).dtTransOffset = 81;
	
	  ;% test_P.DeadZone_End
	  section.data(83).logicalSrcIdx = 82;
	  section.data(83).dtTransOffset = 82;
	
	  ;% test_P.Gain_Gain_k
	  section.data(84).logicalSrcIdx = 83;
	  section.data(84).dtTransOffset = 83;
	
	  ;% test_P.Delay_InitialCondition_p
	  section.data(85).logicalSrcIdx = 84;
	  section.data(85).dtTransOffset = 84;
	
	  ;% test_P.DiscreteTimeIntegrator_gainva_p
	  section.data(86).logicalSrcIdx = 85;
	  section.data(86).dtTransOffset = 85;
	
	  ;% test_P.DiscreteTimeIntegrator_IC_a
	  section.data(87).logicalSrcIdx = 86;
	  section.data(87).dtTransOffset = 86;
	
	  ;% test_P.Saturation_UpperSat
	  section.data(88).logicalSrcIdx = 87;
	  section.data(88).dtTransOffset = 87;
	
	  ;% test_P.Saturation_LowerSat
	  section.data(89).logicalSrcIdx = 88;
	  section.data(89).dtTransOffset = 88;
	
	  ;% test_P.Step_Time
	  section.data(90).logicalSrcIdx = 89;
	  section.data(90).dtTransOffset = 89;
	
	  ;% test_P.Step_Y0
	  section.data(91).logicalSrcIdx = 90;
	  section.data(91).dtTransOffset = 90;
	
	  ;% test_P.Step_YFinal
	  section.data(92).logicalSrcIdx = 91;
	  section.data(92).dtTransOffset = 91;
	
	  ;% test_P.Mass_desired_Value
	  section.data(93).logicalSrcIdx = 92;
	  section.data(93).dtTransOffset = 92;
	
	  ;% test_P.Time_desired_Value
	  section.data(94).logicalSrcIdx = 93;
	  section.data(94).dtTransOffset = 93;
	
	  ;% test_P.Gain2_Gain_m
	  section.data(95).logicalSrcIdx = 94;
	  section.data(95).dtTransOffset = 94;
	
	  ;% test_P.Gain5_Gain
	  section.data(96).logicalSrcIdx = 95;
	  section.data(96).dtTransOffset = 95;
	
	  ;% test_P.Gain3_Gain
	  section.data(97).logicalSrcIdx = 96;
	  section.data(97).dtTransOffset = 96;
	
	  ;% test_P.Gain2_Gain_o
	  section.data(98).logicalSrcIdx = 97;
	  section.data(98).dtTransOffset = 97;
	
	  ;% test_P.Gain5_Gain_d
	  section.data(99).logicalSrcIdx = 98;
	  section.data(99).dtTransOffset = 98;
	
	  ;% test_P.Gain3_Gain_k
	  section.data(100).logicalSrcIdx = 99;
	  section.data(100).dtTransOffset = 99;
	
	  ;% test_P.Constant_Value_j
	  section.data(101).logicalSrcIdx = 100;
	  section.data(101).dtTransOffset = 100;
	
	  ;% test_P.Gain2_Gain_f
	  section.data(102).logicalSrcIdx = 101;
	  section.data(102).dtTransOffset = 103;
	
	  ;% test_P.Gain1_Gain_e
	  section.data(103).logicalSrcIdx = 102;
	  section.data(103).dtTransOffset = 104;
	
	  ;% test_P.Gain_Gain_i
	  section.data(104).logicalSrcIdx = 103;
	  section.data(104).dtTransOffset = 105;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% test_P.Switch_Threshold
	  section.data(1).logicalSrcIdx = 104;
	  section.data(1).dtTransOffset = 0;
	
	  ;% test_P.Switch2_Threshold
	  section.data(2).logicalSrcIdx = 105;
	  section.data(2).dtTransOffset = 1;
	
	  ;% test_P.Switch1_Threshold
	  section.data(3).logicalSrcIdx = 106;
	  section.data(3).dtTransOffset = 2;
	
	  ;% test_P.Switch_Threshold_j
	  section.data(4).logicalSrcIdx = 107;
	  section.data(4).dtTransOffset = 3;
	
	  ;% test_P.Switch2_Threshold_k
	  section.data(5).logicalSrcIdx = 108;
	  section.data(5).dtTransOffset = 4;
	
	  ;% test_P.Switch1_Threshold_j
	  section.data(6).logicalSrcIdx = 109;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% test_P.Gain_Gain_g
	  section.data(1).logicalSrcIdx = 110;
	  section.data(1).dtTransOffset = 0;
	
	  ;% test_P.Gain4_Gain
	  section.data(2).logicalSrcIdx = 111;
	  section.data(2).dtTransOffset = 1;
	
	  ;% test_P.Gain1_Gain_c
	  section.data(3).logicalSrcIdx = 112;
	  section.data(3).dtTransOffset = 2;
	
	  ;% test_P.Gain_Gain_f
	  section.data(4).logicalSrcIdx = 113;
	  section.data(4).dtTransOffset = 3;
	
	  ;% test_P.Gain4_Gain_d
	  section.data(5).logicalSrcIdx = 114;
	  section.data(5).dtTransOffset = 4;
	
	  ;% test_P.Gain1_Gain_i
	  section.data(6).logicalSrcIdx = 115;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (test_B)
    ;%
      section.nData     = 23;
      section.data(23)  = dumData; %prealloc
      
	  ;% test_B.RateTransition
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% test_B.Mass_desired
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% test_B.Time_desired
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% test_B.DigitalClock
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% test_B.Sum
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% test_B.y
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 7;
	
	  ;% test_B.Gain
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 10;
	
	  ;% test_B.Gain1
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 16;
	
	  ;% test_B.DiscreteTimeIntegrator
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 25;
	
	  ;% test_B.DiscreteTimeIntegrator1
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 26;
	
	  ;% test_B.DiscreteTimeIntegrator2
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 27;
	
	  ;% test_B.DiscreteTimeIntegrator3
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 28;
	
	  ;% test_B.DiscreteTimeIntegrator4
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 29;
	
	  ;% test_B.DiscreteTimeIntegrator5
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 30;
	
	  ;% test_B.DiscreteTimeIntegrator10
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 31;
	
	  ;% test_B.DiscreteTimeIntegrator11
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 32;
	
	  ;% test_B.DiscreteTimeIntegrator12
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 33;
	
	  ;% test_B.DiscreteTimeIntegrator13
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 34;
	
	  ;% test_B.DiscreteTimeIntegrator14
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 35;
	
	  ;% test_B.DiscreteTimeIntegrator6
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 36;
	
	  ;% test_B.DiscreteTimeIntegrator7
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 37;
	
	  ;% test_B.DiscreteTimeIntegrator8
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 38;
	
	  ;% test_B.DiscreteTimeIntegrator9
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 39;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 11;
    sectIdxOffset = 1;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (test_DW)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% test_DW.obj
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% test_DW.obj_p
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
	  ;% test_DW.obj_pp
	  section.data(2).logicalSrcIdx = 2;
	  section.data(2).dtTransOffset = 1;
	
	  ;% test_DW.obj_g
	  section.data(3).logicalSrcIdx = 3;
	  section.data(3).dtTransOffset = 2;
	
	  ;% test_DW.obj_k
	  section.data(4).logicalSrcIdx = 4;
	  section.data(4).dtTransOffset = 3;
	
	  ;% test_DW.obj_m
	  section.data(5).logicalSrcIdx = 5;
	  section.data(5).dtTransOffset = 4;
	
	  ;% test_DW.obj_f
	  section.data(6).logicalSrcIdx = 6;
	  section.data(6).dtTransOffset = 5;
	
	  ;% test_DW.obj_my
	  section.data(7).logicalSrcIdx = 7;
	  section.data(7).dtTransOffset = 6;
	
	  ;% test_DW.obj_d
	  section.data(8).logicalSrcIdx = 8;
	  section.data(8).dtTransOffset = 7;
	
	  ;% test_DW.obj_pl
	  section.data(9).logicalSrcIdx = 9;
	  section.data(9).dtTransOffset = 8;
	
	  ;% test_DW.obj_du
	  section.data(10).logicalSrcIdx = 10;
	  section.data(10).dtTransOffset = 9;
	
	  ;% test_DW.obj_pu
	  section.data(11).logicalSrcIdx = 11;
	  section.data(11).dtTransOffset = 10;
	
	  ;% test_DW.obj_c
	  section.data(12).logicalSrcIdx = 12;
	  section.data(12).dtTransOffset = 11;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% test_DW.obj_km
	  section.data(1).logicalSrcIdx = 13;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% test_DW.obj_l
	  section.data(1).logicalSrcIdx = 14;
	  section.data(1).dtTransOffset = 0;
	
	  ;% test_DW.obj_ma
	  section.data(2).logicalSrcIdx = 15;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 24;
      section.data(24)  = dumData; %prealloc
      
	  ;% test_DW.Delay_DSTATE
	  section.data(1).logicalSrcIdx = 16;
	  section.data(1).dtTransOffset = 0;
	
	  ;% test_DW.DiscreteTimeIntegrator_DSTATE
	  section.data(2).logicalSrcIdx = 17;
	  section.data(2).dtTransOffset = 1;
	
	  ;% test_DW.Delay_DSTATE_g
	  section.data(3).logicalSrcIdx = 18;
	  section.data(3).dtTransOffset = 2;
	
	  ;% test_DW.Delay1_DSTATE
	  section.data(4).logicalSrcIdx = 19;
	  section.data(4).dtTransOffset = 3;
	
	  ;% test_DW.Delay2_DSTATE
	  section.data(5).logicalSrcIdx = 20;
	  section.data(5).dtTransOffset = 4;
	
	  ;% test_DW.Delay_DSTATE_l
	  section.data(6).logicalSrcIdx = 21;
	  section.data(6).dtTransOffset = 5;
	
	  ;% test_DW.Delay1_DSTATE_k
	  section.data(7).logicalSrcIdx = 22;
	  section.data(7).dtTransOffset = 6;
	
	  ;% test_DW.Delay2_DSTATE_c
	  section.data(8).logicalSrcIdx = 23;
	  section.data(8).dtTransOffset = 7;
	
	  ;% test_DW.DiscreteTimeIntegrator_DSTATE_b
	  section.data(9).logicalSrcIdx = 24;
	  section.data(9).dtTransOffset = 8;
	
	  ;% test_DW.DiscreteTimeIntegrator1_DSTATE
	  section.data(10).logicalSrcIdx = 25;
	  section.data(10).dtTransOffset = 9;
	
	  ;% test_DW.DiscreteTimeIntegrator2_DSTATE
	  section.data(11).logicalSrcIdx = 26;
	  section.data(11).dtTransOffset = 10;
	
	  ;% test_DW.DiscreteTimeIntegrator3_DSTATE
	  section.data(12).logicalSrcIdx = 27;
	  section.data(12).dtTransOffset = 11;
	
	  ;% test_DW.DiscreteTimeIntegrator4_DSTATE
	  section.data(13).logicalSrcIdx = 28;
	  section.data(13).dtTransOffset = 12;
	
	  ;% test_DW.DiscreteTimeIntegrator5_DSTATE
	  section.data(14).logicalSrcIdx = 29;
	  section.data(14).dtTransOffset = 13;
	
	  ;% test_DW.DiscreteTimeIntegrator10_DSTATE
	  section.data(15).logicalSrcIdx = 30;
	  section.data(15).dtTransOffset = 14;
	
	  ;% test_DW.DiscreteTimeIntegrator11_DSTATE
	  section.data(16).logicalSrcIdx = 31;
	  section.data(16).dtTransOffset = 15;
	
	  ;% test_DW.DiscreteTimeIntegrator12_DSTATE
	  section.data(17).logicalSrcIdx = 32;
	  section.data(17).dtTransOffset = 16;
	
	  ;% test_DW.DiscreteTimeIntegrator13_DSTATE
	  section.data(18).logicalSrcIdx = 33;
	  section.data(18).dtTransOffset = 17;
	
	  ;% test_DW.DiscreteTimeIntegrator14_DSTATE
	  section.data(19).logicalSrcIdx = 34;
	  section.data(19).dtTransOffset = 18;
	
	  ;% test_DW.DiscreteTimeIntegrator6_DSTATE
	  section.data(20).logicalSrcIdx = 35;
	  section.data(20).dtTransOffset = 19;
	
	  ;% test_DW.DiscreteTimeIntegrator7_DSTATE
	  section.data(21).logicalSrcIdx = 36;
	  section.data(21).dtTransOffset = 20;
	
	  ;% test_DW.DiscreteTimeIntegrator8_DSTATE
	  section.data(22).logicalSrcIdx = 37;
	  section.data(22).dtTransOffset = 21;
	
	  ;% test_DW.DiscreteTimeIntegrator9_DSTATE
	  section.data(23).logicalSrcIdx = 38;
	  section.data(23).dtTransOffset = 22;
	
	  ;% test_DW.RateTransition_Buffer0
	  section.data(24).logicalSrcIdx = 39;
	  section.data(24).dtTransOffset = 23;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% test_DW.Scope_time2_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 40;
	  section.data(1).dtTransOffset = 0;
	
	  ;% test_DW.Scope_time3_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 41;
	  section.data(2).dtTransOffset = 1;
	
	  ;% test_DW.Scope_accel_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 42;
	  section.data(3).dtTransOffset = 2;
	
	  ;% test_DW.Scope_angles_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 43;
	  section.data(4).dtTransOffset = 3;
	
	  ;% test_DW.Scope_time_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 44;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% test_DW.DiscreteTimeIntegrator_PrevRese
	  section.data(1).logicalSrcIdx = 45;
	  section.data(1).dtTransOffset = 0;
	
	  ;% test_DW.Running_SubsysRanBC
	  section.data(2).logicalSrcIdx = 46;
	  section.data(2).dtTransOffset = 1;
	
	  ;% test_DW.Intialization_SubsysRanBC
	  section.data(3).logicalSrcIdx = 47;
	  section.data(3).dtTransOffset = 2;
	
	  ;% test_DW.IfActionSubsystem3_SubsysRanBC
	  section.data(4).logicalSrcIdx = 48;
	  section.data(4).dtTransOffset = 3;
	
	  ;% test_DW.IfActionSubsystem1_SubsysRanBC
	  section.data(5).logicalSrcIdx = 49;
	  section.data(5).dtTransOffset = 4;
	
	  ;% test_DW.IfActionSubsystem2_SubsysRanBC
	  section.data(6).logicalSrcIdx = 50;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% test_DW.I2CMasterWrite_p.obj
	  section.data(1).logicalSrcIdx = 67;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% test_DW.I2CMasterWrite_p.objisempty
	  section.data(1).logicalSrcIdx = 68;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% test_DW.I2CMasterWrite.obj
	  section.data(1).logicalSrcIdx = 69;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% test_DW.I2CMasterWrite.objisempty
	  section.data(1).logicalSrcIdx = 70;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(11) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 2118232500;
  targMap.checksum1 = 1677254575;
  targMap.checksum2 = 2372940222;
  targMap.checksum3 = 1776357827;

