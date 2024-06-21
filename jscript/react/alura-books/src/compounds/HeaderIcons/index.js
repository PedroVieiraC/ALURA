import profile from '../img/perfil.svg';
import sacola from '../img/sacola.svg';
import styled from 'styled-components';

const Icon = styled.li`
    margin-right: 40px;
    width: 25px;
    cursor: pointer;
`;

const Icons = styled.ul`
    display: flex;
    align-items: center;
`

const icons = [profile, sacola];

function HeaderIcons() {
    return (
        <Icons>
            {icons.map((icon, index) => (
                <Icon key={index}><img src={icon} alt='icon' /></Icon>
            ))}
        </Icons>
    )
}

export default HeaderIcons;
