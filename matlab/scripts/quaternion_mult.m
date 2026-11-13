%% Quaternion Multiplication

function q_3 = quaternion_mult( q_1, q_2)
    % formel: https://de.mathworks.com/help/aeroblks/quaternionmultiplication.html
    q3_0 = q_1(1)*q_2(1) - q_1(2)*q_2(2) - q_1(3)*q_2(3) - q_1(4)*q_2(4);
    q3_1 = q_1(1)*q_2(2) + q_1(2)*q_2(1) + q_1(3)*q_2(4) - q_1(4)*q_2(3);
    q3_2 = q_1(1)*q_2(3) - q_1(2)*q_2(4) + q_1(3)*q_2(1) + q_1(4)*q_2(2);
    q3_3 = q_1(1)*q_2(4) + q_1(2)*q_2(3) - q_1(3)*q_2(2) + q_1(4)*q_2(1);
    
    q_3 = [q3_0 ; q3_1 ; q3_2 ; q3_3];
end